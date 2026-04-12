#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const long double PI = acos(-1.0L);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll dp[110][2][4];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int k;
  cin >> s >> k;
  dp[0][0][0] = 1;
  rep(i, s.size()) {
    int n = s[i]-'0';
    rep(j, 2) {
      int lim;
      if (j) lim = 9;
      else lim = n;
      rep(l, 4) {
        rep(m, lim+1) {
          int num = l+(m>0);
          if (num > 3)
            continue;
          dp[i+1][j || m < n][num] += dp[i][j][l];
        }
      }
    }
  }
  ll ans = dp[s.size()][0][k]+dp[s.size()][1][k];
  cout << ans << endl;
  return 0;
}