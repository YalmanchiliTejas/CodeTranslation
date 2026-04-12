#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

const ll MOD = 1e9 + 7;

void solve(istream& cin, ostream& cout) {
  string k;
  cin >> k;
  int d;
  cin >> d;
  vector<vector<int>> dp(2, vector<int>(d, 0));
  dp[1][0] = 1;
  EACH(v, k) {
    int cmp = v - '0';
    vector<vector<int>> ndp(2, vector<int>(d, 0));
    REP(i, d) {
      REP(j, 10) {
        if (j < cmp) {
          ndp[0][(i + j) % d] += dp[0][i] + dp[1][i];
          ndp[0][(i + j) % d] %= MOD;
        } else if (j == cmp) {
          ndp[0][(i + j) % d] += dp[0][i];
          ndp[0][(i + j) % d] %= MOD;
          ndp[1][(i + j) % d] += dp[1][i];
          ndp[1][(i + j) % d] %= MOD;
        } else {
          ndp[0][(i + j) % d] += dp[0][i];
          ndp[0][(i + j) % d] %= MOD;
        }
      }
    }
    swap(dp, ndp);
  }
  cout << (((dp[0][0] + dp[1][0]) % MOD - 1) + MOD) % MOD << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif
