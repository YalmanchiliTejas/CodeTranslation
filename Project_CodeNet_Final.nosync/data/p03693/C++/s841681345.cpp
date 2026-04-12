#include <iostream>
#include <string>
#include <typeinfo>

int main() {
  int r, g, b;
  std::cin >> r >> g >> b;
  std::cout << (!(std::stoi(std::to_string(g) + std::to_string(b)) % 4) ? "YES\n" : "NO\n");
  return 0;
}
