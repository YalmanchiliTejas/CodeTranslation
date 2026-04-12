#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = SZ(s);
  vector<vector<vector<ll>>> dp(n + 1,
                                vector<vector<ll>>(k + 1, vector<ll>(2, 0)));
  dp[0][k][0] = 1;
  REP(i, n) REP(j, k + 1) {
    ll x = s[i] - '0';
    if (x == 0) {
      // 0
      dp[i + 1][j][0] += dp[i][j][0];
      // 0
      dp[i + 1][j][1] += dp[i][j][1];
      if (j - 1 >= 0) {
        // 1,2,...,9
        dp[i + 1][j - 1][1] += 9 * dp[i][j][1];
      }
    } else {
      if (j - 1 >= 0) {
        // 1,2,...,x-1
        dp[i + 1][j - 1][1] += (x - 1) * dp[i][j][0];
        // 1,2,...,9
        dp[i + 1][j - 1][1] += dp[i][j][1] * 9;
        // x
        dp[i + 1][j - 1][0] += dp[i][j][0];
      }

      // 0
      dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
    }
  }

  cout << dp[n][0][1] + dp[n][0][0] << endl;
}