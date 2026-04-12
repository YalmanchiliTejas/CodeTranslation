#include <bits/stdc++.h>
const int mod = 998244353;
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> dp(m + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ++dp[0];
    int a;
    std::cin >> a;
    for (int j = m; j >= a; --j)
      dp[j] = (dp[j] + dp[j - a]) % mod;
    ans = (ans + dp[m]) % mod;
  }
  std::cout << ans << "\n";
  return 0;
}