#include <bits/stdc++.h>
const int mod = 998244353;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> dp(m + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ++dp[0];
    int a;
    std::cin >> a;
    if (a > m)
      continue; 
    for (int j = m; j >= a; --j)
      dp[j] = (dp[j] + dp[j - a]) % mod;
    ans = (ans + 1ll * (n - i + 1) * dp[m]) % mod;
    dp[m] = 0; 
  }
  std::cout << ans << "\n";
  return 0;
}