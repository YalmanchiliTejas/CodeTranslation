#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

ll dp[101][2][5];
int main() {
  string n;
  ll k;
  cin >> n >> k;
  ll nlen = n.size();
  dp[0][1][0] = 1;
  rep(i, nlen) {
    ll x = n[i] - '0';
    rep(j, 2) rep(k, 4) rep(l, 10) {
      if (j == 1 && l > x) continue;
      dp[i + 1][j == 1 && l == x][k + (l > 0)] += dp[i][j][k];
    }
  }
  cout << dp[nlen][0][k] + dp[nlen][1][k] << endl;
}
