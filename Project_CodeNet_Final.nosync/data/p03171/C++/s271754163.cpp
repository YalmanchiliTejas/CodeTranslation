#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector< vector<long long> > dp(n + 1, vector<long long>(n + 1));
  int sgn = (n & 1) ? 1 : -1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j + i <= n; j++) {
      if (sgn > 0) {
        dp[j][j + i] = max(a[j] + dp[j + 1][j + i],
                           a[j + i - 1] + dp[j][j + i - 1]);
      } else {
        dp[j][j + i] = min(-a[j] + dp[j + 1][j + i],
                           -a[j + i - 1] + dp[j][j + i - 1]);
      }
    }
    sgn *= -1;
  }
  cout << dp[0][n] << '\n';
  return 0;
}