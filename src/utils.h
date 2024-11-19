#pragma once
#include "bridge.h"

namespace utils {
inline void log(const char *message, int type = 0) {
#ifdef _DEBUG
  switch (type) {
  case 0:
    std::cout << "[+] " << message << std::endl;
    break;
  case 1:
    std::cout << "[!] " << message << std::endl;
    break;
  case 2:
    std::cout << "[-] " << message << std::endl;
    break;
  default:
    break;
  }
#endif
}

inline void funcLog(const char *func = __builtin_FUNCTION()) {
#ifdef _DEBUG
  std::string message = func;
  message += " called";

  log(message.c_str(), 1);
#endif
}
} // namespace Utils