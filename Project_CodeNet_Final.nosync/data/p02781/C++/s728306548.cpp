#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

// int dp[105][4][2];

int main() {
  string S;
  cin >> S;
  int n = S.size();
  int K;
  cin >> K;
  
  // dp[i][j][k]
  // i桁目まで決めてj個の非0を使って、
  // k=0：i桁目まではNと一致している
  // k=1：i桁目まででNより小さいことが確定している
  vector<vector<vector<int> > > dp(105, vector<vector<int>>(4, vector<int>(2, 0)));
  dp[0][0][0] = 1;
  rep(i, n) rep(j, 4) rep(k, 2) {
    int nd = S[i] - '0';  // 今の桁
    rep(d, 10) { // 次の桁
      int ni = i + 1, nj = j, nk = k;
      if (d != 0) nj++;
      if (nj > K) continue;
      if (k == 0) {
        if (d > nd) continue;  // Sよりも大きい場合
        if (d < nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }

  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
  return 0;
}
