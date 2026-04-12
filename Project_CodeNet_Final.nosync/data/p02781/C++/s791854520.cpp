#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int dp[101][4][2];


int main() {
  string N; cin >> N;
  int K; cin >> K;
  int n = N.size();

  dp[0][0][0] = 1;

  rep(i, n) {
    int Ni = N[i] - '0'; // N の上から i 桁目の数
    rep(j, K+1) rep(k, 2) rep(x, 10) {
      int j2 = j, k2 = k; // 遷移後の状態を表す変数 j2, k2 を，遷移前の状態で初期化

      if (x != 0) ++j2;     // X の上から i 桁目の数 x が非ゼロなら j2 を更新
      if (j2 > K) continue; // 非ゼロの桁の数が K より多いなら無視

      if (!k && (x > Ni)) continue; // X が N より大きい数であることが確定したら無視
      if (x < Ni) k2 = 1;           // X が N より小さい数であることが確定したら k2 を更新

      dp[i+1][j2][k2] += dp[i][j][k]; // 遷移式
    }
  }

  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << '\n';
}
