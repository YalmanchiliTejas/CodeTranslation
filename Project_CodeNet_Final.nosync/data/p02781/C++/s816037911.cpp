#include <bits/stdc++.h>

using namespace std;

long long dp[110][5][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  int k;
  cin >> s >> k;
  dp[0][0][1] = 1;
  for (int i = 1; i <= s.size(); ++i) {
    for (int j = 0; j <= k; ++j) {
      int x = s[i - 1] - '0';
      if (x == 0) {
        dp[i][j][1] = dp[i - 1][j][1];
        dp[i][j][0] = dp[i - 1][j][0];
      } else {
        dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
      }
      if (j) {
        dp[i][j][0] += 9 * dp[i - 1][j - 1][0];
        if (x != 0) {
          dp[i][j][0] += (x - 1) * dp[i - 1][j - 1][1];
          dp[i][j][1] += dp[i - 1][j - 1][1];
        }
      }
    }
  }
  cout << dp[s.size()][k][0] + dp[s.size()][k][1];

  return 0;
}