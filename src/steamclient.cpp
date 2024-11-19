#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define S_API extern "C" __declspec(dllexport)

S_API void Breakpad_SteamMiniDumpInit() {}

S_API void Breakpad_SteamSetAppID() {}

S_API int Breakpad_SteamSetSteamID() { return 0; }

S_API int Breakpad_SteamWriteMiniDumpSetComment() { return 0; }

S_API void Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId() {}

S_API bool Steam_BConnected() { return true; }

S_API bool Steam_BLoggedOn() { return true; }

S_API int CreateInterface() {
  int iProcAddr = 0;
  HMODULE hModule = 0;

  if (!iProcAddr) {
#ifdef _WIN64
    hModule = GetModuleHandleA("steam_api64.dll");
#else
    hModule = GetModuleHandleA("steam_api.dll");
#endif
    if (hModule)
      iProcAddr = GetProcAddress(hModule, "SteamInternal_CreateInterface")();
  }

  return iProcAddr;
}