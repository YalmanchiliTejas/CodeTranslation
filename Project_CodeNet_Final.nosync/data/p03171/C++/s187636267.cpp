#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> in(n);
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  static long long dp[3456][3456] = {};
  for (int x = 1; x <= n; x++) {
    for (int i = 0; i + x <= n; i++) {
      int j = i + x;
      if ((n - x) % 2 == 0) {
        dp[i][j] = max(dp[i + 1][j] + in[i], dp[i][j - 1] + in[j - 1]);
      } else {
        dp[i][j] = min(dp[i + 1][j] - in[i], dp[i][j - 1] - in[j - 1]);
      }
    }
  }
  cout << dp[0][n] << endl;
  return 0;
}