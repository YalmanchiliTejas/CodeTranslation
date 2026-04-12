#include <bits/stdc++.h>

int main() {
  int x, y, z;
  std::cin >> x >> y >> z;
  x -= z;
  std::cout << x / (y + z) << std::endl;
  return 0;
}
