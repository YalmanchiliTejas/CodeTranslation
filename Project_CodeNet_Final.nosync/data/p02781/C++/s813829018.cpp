#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

ll dp[101][4][2] = {};
int main() {
  string n;
  cin >> n;
  int k;
  cin >> k;

  ll init = n[0] - '0';
  dp[1][1][1] = 1;
  dp[1][0][0] = 1;
  dp[1][1][0] = init - 1;

  int size = n.length();
  FOR(i, 1, size) {
    int num = n[i] - '0';
    dp[i + 1][0][0] = dp[i][0][0];
    dp[i + 1][0][1] = 0;
    FOR(j, 1, k + 1) {
      dp[i + 1][j][0] = dp[i][j][0] + dp[i][j - 1][0] * 9;
      if (num != 0) {
        dp[i + 1][j][0] += dp[i][j][1] + dp[i][j - 1][1] * (num - 1);
      }
      if (num == 0) {
        dp[i + 1][j][1] = dp[i][j][1];
      } else {
        dp[i + 1][j][1] = dp[i][j - 1][1];
      }
    }
  }

  ll ans = dp[size][k][0] + dp[size][k][1];
  cout << ans << endl;

  return 0;
}
