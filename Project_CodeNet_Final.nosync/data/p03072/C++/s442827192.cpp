#include <algorithm>
#include <iostream>

auto main() -> int {
  int n;
  std::cin >> n;

  int hs[20];
  for (int i = 0; i < n; ++i) {
    std::cin >> hs[i];
  }

  int o = 0;
  int maximum = 0;
  for (int i = 0; i < n; ++i) {
    maximum = std::max(maximum, hs[i]);
    if (maximum <= hs[i]) o++;
  }

  std::cout << o << std::endl;
}
