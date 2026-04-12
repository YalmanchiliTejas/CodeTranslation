#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //e
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = (int) s.size();
  long long dp[110][2][5] = {};
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int x = s[i] - '0';
    for (int j = 0; j <= k; j++) for (int d = 0; d < 10; d++) {
      if (d < x) {
        if (d == 0) {
          dp[i + 1][1][j] += dp[i][1][j];
          dp[i + 1][1][j] += dp[i][0][j];
        } else if (j < k) {
          dp[i + 1][1][j + 1] += dp[i][1][j];
          dp[i + 1][1][j + 1] += dp[i][0][j];
        }
      } else if (d == x) {
        if (d == 0) {
          dp[i + 1][1][j] += dp[i][1][j];
          dp[i + 1][0][j] += dp[i][0][j];
        } else if (j < k) {
          dp[i + 1][1][j + 1] += dp[i][1][j];
          dp[i + 1][0][j + 1] += dp[i][0][j];
        }
      } else {
        if (d == 0) {
          dp[i + 1][1][j] += dp[i + 1][1][j];
        } else if (j < k) {
          dp[i + 1][1][j + 1] += dp[i][1][j];
        }
      }
    }
  }
  cout << dp[n][0][k] + dp[n][1][k] << endl;
  return 0;
}