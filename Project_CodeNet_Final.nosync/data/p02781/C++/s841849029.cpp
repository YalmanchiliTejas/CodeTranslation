#include <iostream>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int dp[s.size()][k + 1][2];
  for (int i = 0; i <= k; ++i) {
    dp[0][i][0] = 0;
    dp[0][i][1] = 0;
  }
  dp[0][0][0] = 1;
  dp[0][1][0] = s[0] - '0' - 1;
  dp[0][1][1] = 1;
  for (int i = 1; i < s.size(); ++i) {
    dp[i][0][0] = 1;
    dp[i][0][1] = 0;
    for (int j = 1; j <= k; ++j) {
      dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j - 1][0] * 9;
      if (s[i] == '0') {
        dp[i][j][1] = dp[i - 1][j][1];
      } else {
        dp[i][j][1] = dp[i - 1][j - 1][1];
        dp[i][j][0] += dp[i - 1][j - 1][1] * (s[i] - '0' - 1) + dp[i - 1][j][1];
      }
    }
  }
  cout << dp[s.size() - 1][k][0] + dp[s.size() - 1][k][1];
  return 0;
}
