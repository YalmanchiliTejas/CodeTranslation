#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  string N;
  ll K;
  cin >> N >> K;
  ll dp[N.size() + 1][2]
       [5];  // dp[上からi桁目まで][N以下確定か][0でない数の個数]
  reverse(N.begin(), N.end());
  REP(i, N.size() + 1) REP(j, 2) REP(k, 5) dp[i][j][k] = 0;
  dp[N.size() - 1][1][1] = N[N.size() - 1] - '0' - 1;
  dp[N.size() - 1][0][1] = 1;
  dp[N.size() - 1][1][0] = 1;
  for (int i = N.size() - 1; i > 0; i--) {
    for (int j = 0; j <= 9; j++) {
      REP(k, 4) {
        if (j == 0) {
          dp[i - 1][1][k] += dp[i][1][k];
        } else {
          dp[i - 1][1][k + 1] += dp[i][1][k];
        }
      }
    }
    for (int j = 0; j <= N[i - 1] - '0'; j++) {
      REP(k, 4) {
        if (j != N[i - 1] - '0') {
          if (j == 0) {
            dp[i - 1][1][k] += dp[i][0][k];
          } else {
            dp[i - 1][1][k + 1] += dp[i][0][k];
          }
        } else {
          if (j == 0) {
            dp[i - 1][0][k] += dp[i][0][k];
          } else {
            dp[i - 1][0][k + 1] += dp[i][0][k];
          }
        }
      }
    }
  }
  cout << dp[0][1][K] + dp[0][0][K] << endl;
  int a = 10;
}