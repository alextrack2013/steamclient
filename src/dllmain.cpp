#include "bridge.h"

FILE *stream;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
  case DLL_PROCESS_ATTACH:
#ifdef _DEBUG
    FreeConsole();
    if (!AttachConsole(0))
      AllocConsole();
    freopen_s(&stream, "CONOUT$", "w", stdout);
    SetConsoleTitleA("steamclient");
    system("cls");

    utils::log("Attached to process successfully!");
    break;
#endif
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
    break;
  }
  return TRUE;
}
