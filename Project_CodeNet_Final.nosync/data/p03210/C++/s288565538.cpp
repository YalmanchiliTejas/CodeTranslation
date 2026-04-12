#include <algorithm>
#include <array>
#include <bitset>
#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <vector>

// constexpr std::int64_t INF = 1ull << 50;
constexpr int INF = 1 << 20;

auto main() -> int {
  int X;
  std::cin >> X;

  if (X == 7 || X == 5 || X == 3) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}
