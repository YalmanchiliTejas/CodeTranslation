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
  for (auto &e : a)
    std::cin >> e;
  
  std::vector<i64> dp(t, 0);
  for (int i = 0; i < m; i += 1) {
    for (int j = 0; j < t; j += 1)
      dp[j] += a[2 * i + j];
    for (int j = 1; j < t; j += 1)
      dp[j] = std::max(dp[j], dp[j - 1]);
  }
  std::cout << dp.back() << "\n";
}
  