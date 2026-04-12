#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();

  // dp[桁数][k(1〜9を何個含むか)][未満フラグ]
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 2, vector<ll>(2)));

  // 初期条件
  // 最上位桁+1桁目を便宜上0とする。
  // このとき、未満フラグOffの数値が1種類存在することになる。
  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      int D = s[i] - '0';

      for (int h = 0; h <= 9; h++) {
        // この桁を0にする場合
        // dp[i + 1][j][0 or 1]
        if (h == 0) {
          //未満フラグOnのものはそのまま引き継ぎ
          dp[i + 1][j][1] += dp[i][j][1];

          // 未満フラグOffのものの引き継ぎ方を決定
          if (h == D) {
            // 未満フラグOff→Offで引き継ぎ
            dp[i + 1][j][0] += dp[i][j][0];
          } else if (h < D) {
            // 該当桁の値Dが1以上なら未満フラグOff→Onで引き継ぎ
            dp[i + 1][j][1] += dp[i][j][0];
          }
        }
        // この桁を0以外にする場合([k]が変化する)
        // dp[i + 1][j + 1][0 or 1]
        else {
          // 未満フラグOnのものはそのまま引き継ぎ
          dp[i + 1][j + 1][1] += dp[i][j][1];

          if (h == D) {
            // 未満フラグOff→Offで引き継ぎ
            dp[i + 1][j + 1][0] += dp[i][j][0];
          } else if (h < D) {
            // 未満フラグOff→Onで引き継ぎ
            dp[i + 1][j + 1][1] += dp[i][j][0];
          }
        }
      }
    }
  }
  ll ans = dp[n][k][0] + dp[n][k][1];
  cout << ans << endl;
}