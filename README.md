# A64Dbg/VMPStudio Pro (UVMDbg/UVMFire) LaunchAPK glues.
### This method can bypass any anti-ptrace protection.

## How it works
```mermaid
sequenceDiagram
    A64Dbg/VMPStudio->>Zygote: LaunchAPK
    Zygote->>App: zygisk::ModuleBase:postAppSpecialize
    App->>libadzygote/libuvmzygote: ADZygisk/UVMZygisk
    libadzygote/libuvmzygote->>libuvmdbg.so/libuvmfire.so: dlopen
    libuvmdbg.so/libuvmfire.so->>A64Dbg/VMPStudio: Connect
```
