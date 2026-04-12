#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  vector<vector<long long>> dp;
  dp.assign(n + 1, vector<long long>(3, -1e18));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= 2; ++j) {
      if (dp[max(0, i - 1)][j] != -1e18)
        dp[i + 1][j] = dp[max(0, i - 1)][j] + a[i];
      if (j != 0 && i >= 3 && dp[i - 2][j - 1] != 1e18)
        dp[i + 1][j] = max(dp[i + 1][j], dp[i - 2][j - 1] + a[i]);
    }
  }
  long long res = 0;
  for (int i = n - 1; i > 0; i -= 2) res += a[i];
  if (n % 2) res = max(res, dp[n][2]);
  res = max(res, dp[n][1]);
  if (n % 2) res = max(res, dp[n - 1][1]);
  res = max({res, dp[n - 1][0]});
  return res;
}
