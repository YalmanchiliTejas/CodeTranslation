#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

// dp[i][j][k]
// i桁目まで決めて、
// j個のnon0を使って。
// k:0そこまでの桁はnと一致
// k:1そこまでの桁はn未満

int main() {
  string s;
  ll k, n;
  cin >> s >> k;
  n = s.size();
  ll dp[101][4][2]{};
  dp[0][0][0] = 1;

  rep(i, n) rep(j, 4) rep(l, 2) {
    ll nd = s[i] - '0';
    rep(d, 10) {
      int nj = j, nl = l;
      if (d) nj++;
      if (nj > k) continue;
      if (nl == 0) {
        if (d < nd) nl = 1;
        if (d > nd) continue;
      }
      dp[i + 1][nj][nl] += dp[i][j][l];
    }
  }

  cout << dp[n][k][0] + dp[n][k][1] << endl;
  return 0;
}
