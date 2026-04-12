#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
ll dp[20000][7][2];
int main() {
  string N;
  ll K;
  cin >> N >> K;
  dp[0][0][0] = 1, dp[0][0][1] = 1;
  REP(i, N.size()) {
    if (i != 0) {
      REP(j, 5) {
        dp[i + 1][j + 1][0] += 9 * dp[i][j][0];
        dp[i + 1][j][0] += dp[i][j][0];
      }
    }
    REP(j, 5) {
      if (N[i] == '0') {
        dp[i + 1][j][1] += dp[i][j][1];
      } else {
        dp[i + 1][j][0] += dp[i][j][1];
        dp[i + 1][j + 1][0] += (N[i] - '0' - 1) * dp[i][j][1];
        dp[i + 1][j + 1][1] += dp[i][j][1];
      }
    }
  }
  cout << (dp[N.size()][K][0] + dp[N.size()][K][1]) << endl;
}