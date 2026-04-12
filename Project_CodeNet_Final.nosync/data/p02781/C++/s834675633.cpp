#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;

int main() {
  string s;
  ll m;
  cin >> s;
  cin >> m;

  ll dp[105][2][m + 2];
  REP(i, 105) REP(j, 2) REP(k, m + 2) { dp[i][j][k] = 0; }
  dp[0][0][0] = 1;

  REP(i, s.length()) {
    REP(k, m + 1) {
      dp[i + 1][1][k + 1] += dp[i][1][k] * 9;
      dp[i + 1][1][k] += dp[i][1][k];

      if (s[i] != '0') {
        dp[i + 1][1][k + 1] += dp[i][0][k] * (s[i] - '0' - 1);
        dp[i + 1][1][k] += dp[i][0][k];
      }

      if (s[i] != '0') {
        dp[i + 1][0][k + 1] += dp[i][0][k];

      } else {
        dp[i + 1][0][k] += dp[i][0][k];
      }
    }
  }

  ll ans = 0;
  REP(j, 2) ans += dp[s.length()][j][m];

  cout << ans << endl;
  return 0;
}