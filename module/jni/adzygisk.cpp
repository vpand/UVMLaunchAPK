/* Copyright 2022-2023 John "topjohnwu" Wu
 * Copyright 2024 vpand.com
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include <cstdlib>
#include <unistd.h>
#include <dlfcn.h>
#include <android/log.h>

#include "zygisk.hpp"

using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "ADZygoteModule", __VA_ARGS__)

class ADZygoteModule : public zygisk::ModuleBase {
public:
    void onLoad(Api *api, JNIEnv *env) override {
        this->api = api;
        this->env = env;
    }

    void postAppSpecialize(const AppSpecializeArgs *args) override {
#if __arm__
#define AD_ARCH "arm"
#elif __aarch64__ || __arm64__
#define AD_ARCH "arm64"
#elif __x86_64__
#define AD_ARCH "x86_64"
#else
#define AD_ARCH "x86"
#endif
        // notify a64dbg in its ctor function
        dlopen("/data/local/tmp/a64dbg-server-" AD_ARCH ".uvm/libadzygote.so", RTLD_NOW);
    }

private:
    Api *api;
    JNIEnv *env;
};

static void companion_handler(int i) {}

// Register our module class and the companion handler function
REGISTER_ZYGISK_MODULE(ADZygoteModule)
REGISTER_ZYGISK_COMPANION(companion_handler)
