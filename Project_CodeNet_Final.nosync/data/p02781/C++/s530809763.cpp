#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int dp[101][4][2];


int main() {
  string s; cin >> s;
  int K; cin >> K;
  int n = s.size();

  dp[0][0][0] = 1;

  rep(i, n) {
    int ni = s[i] - '0'; // N の上から i 桁目の数
    rep(j, K+1) rep(k, 2) rep(x, 10) {
      int j2 = j, k2 = k; // 遷移前の状態をコピーする

      if (x != 0) ++j2;     // 次に使う数 x が非ゼロなら j2 を更新
      if (j2 > K) continue; // 非ゼロの数が K より大きいことが確定したら無視

      if (!k && (x > ni)) continue; // N より大きい数であることが確定したら無視
      if (x < ni) k2 = 1;           // N より小さい数であることが確定したら k2 を更新

      dp[i+1][j2][k2] += dp[i][j][k]; // 遷移式
    }
  }

  cout << (dp[n][K][0] + dp[n][K][1]) << '\n';
}
