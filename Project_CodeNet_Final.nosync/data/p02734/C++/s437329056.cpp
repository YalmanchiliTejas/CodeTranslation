#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  ll n, s;
  cin >> n >> s;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll dp[n + 1][s + 1][3];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  rep(i, n) {
    rep(j, s + 1) {
      dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][0]) % mod2;
      dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0] + dp[i][j][1]) % mod2;
      dp[i + 1][j][2] = (dp[i + 1][j][2] + dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) % mod2;
      if (j + a[i] <= s) {
        dp[i + 1][j + a[i]][1] = (dp[i + 1][j + a[i]][1] + dp[i][j][0] + dp[i][j][1]) % mod2;
        dp[i + 1][j + a[i]][2] = (dp[i + 1][j + a[i]][2] + dp[i][j][0] + dp[i][j][1]) % mod2;
      }
    }
  }
  cout << dp[n][s][2] << endl;




  
  return 0;
}