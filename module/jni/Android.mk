LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := adzygisk
LOCAL_SRC_FILES := adzygisk.cpp
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := uvmzygisk
LOCAL_SRC_FILES := uvmzygisk.cpp
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)
