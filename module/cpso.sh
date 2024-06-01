cp -f libs/arm64-v8a/libadzygisk.so ../com.vpand.adzygisk/zygisk/arm64-v8a.so
cp -f libs/armeabi-v7a/libadzygisk.so ../com.vpand.adzygisk/zygisk/armeabi-v7a.so
cp -f libs/x86/libadzygisk.so ../com.vpand.adzygisk/zygisk/x86.so
cp -f libs/x86_64/libadzygisk.so ../com.vpand.adzygisk/zygisk/x86_64.so

cp -f libs/arm64-v8a/libuvmzygisk.so ../com.vpand.uvmzygisk/zygisk/arm64-v8a.so
cp -f libs/armeabi-v7a/libuvmzygisk.so ../com.vpand.uvmzygisk/zygisk/armeabi-v7a.so
cp -f libs/x86/libuvmzygisk.so ../com.vpand.uvmzygisk/zygisk/x86.so
cp -f libs/x86_64/libuvmzygisk.so ../com.vpand.uvmzygisk/zygisk/x86_64.so

echo Done.
