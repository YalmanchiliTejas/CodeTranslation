/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t L, X;
  cin >> L >> X;
  vector<int64_t> N(L + 1, 1);
  vector<int64_t> P(L + 1, 1);
  for (int64_t i = 1; i <= L; ++i) {
    N[i] = 2 * N[i - 1] + 3;
    P[i] = 2 * P[i - 1] + 1;
    // cerr << i << ", " << P[i] << endl;
  }
  auto Get = [&](auto &&Func, const int64_t level, const int64_t n) -> int64_t {
    if (level == 0) {
      return 1;
    } else if (n <= 1) {
      return 0;
    } else if (n >= N[level]) {
      return P[level];
    } else if (n <= N[level - 1] + 1) {
      return Func(Func, level - 1, n - 1);
    } else if (n <= N[level - 1] + 2) {
      return Func(Func, level - 1, n - 1) + 1;
    } else {
      return P[level - 1] + 1 + Func(Func, level - 1, n - 2 - N[level - 1]);
    }
  };
  cout << Get(Get, L, X) << endl;
  return 0;
}
