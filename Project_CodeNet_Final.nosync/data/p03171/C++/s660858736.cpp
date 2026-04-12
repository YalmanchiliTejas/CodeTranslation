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

const ll MOD = 1e9 + 7;

void solve(istream& cin, ostream& cout) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  REP(i, n) {
    cin >> a[i];
  }

  REP(i, n) {
    if (n % 2) {
      dp[i][i] = a[i];
    } else {
      dp[i][i] = - a[i];
    }
  }

  FOR(l, 1, n - 1) {
    REP(i, n - l) {
      if ((n - l) % 2) {
        dp[i][i + l] = max(dp[i][i + l - 1] + a[i + l], dp[i + 1][i + l] + a[i]);
      } else {
        dp[i][i + l] = min(dp[i][i + l - 1] - a[i + l], dp[i + 1][i + l] - a[i]);
      }
    }
  }

  cout << dp[0][n - 1] << endl;

}

#ifndef TEST
int main() {
  solve(cin, cout);
}
#endif
