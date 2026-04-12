#include <bits/stdc++.h>
using namespace std;

string s;
int k;
long dp[101][5][2];
int main() {
  cin >> s >> k;
  const int n = s.size();
  dp[0][0][1] = 1;
  for (int i = 0; i < n; ++i) {
    int d = s[i] - '0';
    for (int j = 0; j <= k; ++j) {
      if (d == 0) {
        dp[i + 1][j + 0][1] += dp[i][j][1];
        dp[i + 1][j + 0][0] += dp[i][j][0];
        dp[i + 1][j + 1][0] += 9 * dp[i][j][0];
      } else {
        dp[i + 1][j + 0][0] += dp[i][j][1];
        dp[i + 1][j + 1][0] += (d - 1) * dp[i][j][1];
        dp[i + 1][j + 1][1] += dp[i][j][1];
        dp[i + 1][j + 0][0] += dp[i][j][0];
        dp[i + 1][j + 1][0] += 9 * dp[i][j][0];
      }
    }
  }
  cout << dp[n][k][0] + dp[n][k][1] << endl;
}