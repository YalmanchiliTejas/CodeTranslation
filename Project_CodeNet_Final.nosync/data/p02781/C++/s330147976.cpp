#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string N;
  int K;
  cin >> N >> K;
  int m = N.length();
  // 0 確定，1 未確定
  vector<vector<vector<long long>>> dp(
      m + 1, vector<vector<long long>>(K + 1, vector<long long>(2, 0)));
  dp[1][0][0] = 1;
  dp[1][1][0] = N[0] - '0' - 1;
  dp[1][1][1] = 1;
  for (int i = 2; i <= m; i++) {
    int top = N[i - 1] - '0';
    for (int j = 0; j <= K; j++) {
      // 0を選ぶ
      if (top == 0) {
        dp[i][j][0] += dp[i - 1][j][0];
        dp[i][j][1] += dp[i - 1][j][1];
      } else {
        dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][1];
      }

      if (j == 0) continue;
      // 0以外を選ぶ
      // N以下が確定する時
      for (int k = 1; k < top; k++) {
        dp[i][j][0] += dp[i - 1][j - 1][1];
      }
      //未確定
      if (top != 0) {
        // topを選んでまだ未確定で続く
        dp[i][j][1] += dp[i - 1][j - 1][1];
      }

      for (int k = 1; k < 10; k++) {
        dp[i][j][0] += dp[i - 1][j - 1][0];
      }
    }
  }

  cout << dp[m][K][0] + dp[m][K][1] << endl;
  return 0;
}
