#include<algorithm>
#include<iostream>
#include<vector>

using i64 = long long;

int main() {
  int n;
  std::cin >> n;
  int m = n / 2;
  int t = n - m * 2 + 2;
  std::vector<i64> a(n);
  for (auto &e : a) std::cin >> e;
  std::vector<i64> dp_(t + 1, 0);
  const auto dp = dp_.begin() + 1;
  dp[-1] = -10000000000000000;
  for (int i = 0; i < m; i += 1) {
    for (int j = 0; j < t; j += 1) {
      dp[j] = std::max(dp[j] + a[2 * i + j], dp[j - 1]);
    }
  }
  std::cout << dp[t - 1] << "\n";
}
  