#include "bridge.h"
#define S_API extern "C" __declspec(dllexport)

S_API void Breakpad_SteamMiniDumpInit() { utils::funcLog(); }

S_API void Breakpad_SteamSetAppID() { utils::funcLog(); }

S_API int Breakpad_SteamSetSteamID() {
  utils::funcLog();
  return 0;
}

S_API int Breakpad_SteamWriteMiniDumpSetComment() {
  utils::funcLog();
  return 0;
}

S_API void Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId() {
  utils::funcLog();
}

S_API bool Steam_BConnected() {
  utils::funcLog();
  return true;
}

S_API bool Steam_BLoggedOn() {
  utils::funcLog();
  return true;
}

S_API int CreateInterface() {
  utils::funcLog();
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