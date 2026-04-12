#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <utility>
#include <vector>

int main() {
  using i64 = long long;
  constexpr i64 MInf = std::numeric_limits<i64>::lowest() / 2;

  int n;
  std::cin >> n;
  std::vector<i64> a(n);
  for (auto &e : a) {
    std::cin >> e;
  }

  std::map<std::pair<int, int>, i64> memo;
  std::function<i64(int, int)> solve, calc;

  solve = [&](int i, int k) -> i64 {
    auto itr = memo.find({i, k});
    if (itr == memo.end()) {
      itr = memo.insert({{i, k}, calc(i, k)}).first;
    }
    return itr->second;
  };

  calc = [&](int i, int k) -> i64 {
    if (k < 0 || (i + 1) / 2 < k)
      return MInf;
    if (i <= 0)
      return 0;
    return std::max(solve(i - 1, k), solve(i - 2, k - 1) + a[i - 1]);
  };

  std::cout << solve(n, n / 2) << "\n";
}
