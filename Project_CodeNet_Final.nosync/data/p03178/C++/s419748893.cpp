#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

ll dp[10001][2][100] = {};

int main() {
  string k;
  int d;
  cin >> k;
  cin >> d;
  int n = k.length();

  dp[0][0][0] = 1;
  REP(_i, n) {
    int i = _i + 1;
    int D = k[_i] - '0';
    REP(j, d) {
      REP(digit, D) {
        dp[i][1][(j + digit) % d] =
            (dp[i][1][(j + digit) % d] + dp[i - 1][0][j]) % MOD;
      }
      REP(digit, 10) {
        dp[i][1][(j + digit) % d] =
            (dp[i][1][(j + digit) % d] + dp[i - 1][1][j]) % MOD;
      }
      dp[i][0][(j + D) % d] = (dp[i][0][(j + D) % d] + dp[i - 1][0][j]) % MOD;
    }
  }

  cout << (dp[n][1][0] + dp[n][0][0] - 1 + MOD) % MOD << endl;
}
