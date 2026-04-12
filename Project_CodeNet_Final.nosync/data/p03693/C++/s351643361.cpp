#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  uint16_t r, g, b = 0;
  std::cin >> r >> g >> b;

  std::cout << ((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO") << std::endl;

  return 0;
}