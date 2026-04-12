#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <limits>
#include <stdio.h>

template <typename T>
void vc(T t) {
    std::cout << t << " ";
}

template<typename T, typename... Args>
void vc(T t, Args... args) {
// recursive variadic function
    std::cout << t << " ";
    vc(args...) ;
}

const int N = 100000;

long long dp[3002][3002];
long long dpx(const std::vector<long long> vi, int l, int r) {
  // vc("x", l, r, "\n");
  if (l > r) {
    return 0;
  }
  if (dp[l][r] != 123456789012345LL) {
    return dp[l][r];
  }
  if (l == r) {
    dp[l][r] = vi[l];
    return vi[l];
  }
  // vc("-", l, r, dp[l][r], vll[0], vll[1], vll[2], vll[3], "\n");
  // vc("+", l, r, dp[l][r], "\n");
  return dp[l][r];
}

void once() {
  int n;
  std::cin >> n;
  std::vector<long long> vi(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> vi[i];
  }

  for (int i = 0; i < 3002; ++i)
    for (int j = 0; j < 3002; ++j)
      dp[i][j] = 0LL;

  for (int len = 0; len < n; ++len) {
    for (int l = 1; l + len <= n; ++l) {
      int r = l + len;
      if (l == r) {
        dp[l][r] = vi[l];
        continue;
      }
      long long vll_0 = vi[l] - vi[l + 1] + dp[l + 2][r]; // ll
      long long vll_1 = vi[l] - vi[r] + dp[l + 1][r - 1]; // lr
      long long vll_2 = vi[r] - vi[l] + dp[l + 1][r - 1]; // rl
      long long vll_3 = vi[r] - vi[r - 1] + dp[l][r - 2]; // rr
      dp[l][r] = std::max(std::min(vll_0, vll_1), std::min(vll_2, vll_3));
    }
  }

  std::cout << dp[1][n] << std::endl;
}

int
main() {
  int n = 1;
  std::ios::sync_with_stdio(false);
  // std::cin >> n;
  while (n--) {
    once();
  }
}