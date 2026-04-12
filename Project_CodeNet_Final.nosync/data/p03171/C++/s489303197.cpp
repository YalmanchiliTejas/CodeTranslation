/*
 *    author:  Gary Shih
 *    created: 2020-05-04 19:20:13
 */
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<vector<long long>> dp(n, vector<long long>(n, INT_MIN));
  for (int i = 0; i < n; ++i) dp[i][i] = ((n & 1) ? a[i] : -a[i]);
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i < n - len + 1; ++i) {
      int j = i + len - 1;
      if ((n - len) & 1) {
        dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
      } else {
        dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
}
