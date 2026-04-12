#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[105][4][2];

int main() {
  // dp[i][j][k] i桁目まで見た時の、0でない数がj個ある数字の個数
  // k=0はpending、k=1はN以下が確定
  string S;
  int K;
  cin >> S >> K;
  int lenS = sz(S);
  dp[0][0][0] = 1;
  rep(i, lenS) rep(j, K+1) rep(k, 2) {
    int cd = S[i] - '0';
    rep(nd, 10) {
      int ni = i+1, nj = j, nk = k;
      if (nd != 0) nj++;
      if (nj > K) continue;
      if (k == 0) {
        if (nd > cd) continue;
        if (nd < cd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[lenS][K][0] + dp[lenS][K][1];
  cout << ans << '\n';  
  return 0;
}
// 35