#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int k;
ll dp[101][2][5];

int main() {
  // INPUT
  cin >> s;
  int n = (int)s.size();
  cin >> k;
  // 初期化
  for (int i = 0; i < 101; i++) for (int j = 0; j < 2; j++) for (int l = 0; l < 5; l++) dp[i][j][l] = 0;
  dp[0][0][0] = 1;
  // ここからDPの遷移定義
  // dp[i][j][l] := 上からi桁目を考えていて、j == 1ならN未満であることが確定、j == 0ならN未満が未確定であり、
  //　上からi桁目までに0以外の数字がl個あるような数の個数
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int l = 0; l <= k; l++) {
        int lim = j == 1 ? 9 : (s[i] - '0');
        for (int m = 0; m <= lim; m++) {
          if (m == lim) {
            if (m == 0) {
              dp[i + 1][j][l] += dp[i][j][l];
            } else {
              dp[i + 1][j][l + 1] += dp[i][j][l];
            }
          } else {
            if (m == 0) {
              dp[i + 1][1][l] += dp[i][j][l];
            } else {
              dp[i + 1][1][l + 1] += dp[i][j][l];
            }
          }
        }
      }
    }
  }
  // 答え
  cout << dp[n][0][k] + dp[n][1][k] << endl;
  return 0;
}
