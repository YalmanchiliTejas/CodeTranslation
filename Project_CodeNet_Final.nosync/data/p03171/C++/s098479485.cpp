#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, 0, N) cin >> A[i];

  const ll INF = 1LL << 60;
  vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(2)));
  REP(i, 0, N) REP(j, 0, N) {
    dp[i][j][0] = -INF;
    dp[i][j][1] = +INF;
  }
  REP(i, 0, N) {
    dp[i][i][0] = +A[i];
    dp[i][i][1] = -A[i];
  }

  REP(k, 2, N + 1) {
    REP(i, 0, N) {
      ll j = i + k - 1;
      if (j >= N) break;
      dp[i][j][0] = max(dp[i + 1][j][1] + A[i], dp[i][j - 1][1] + A[j]);
      dp[i][j][1] = min(dp[i + 1][j][0] - A[i], dp[i][j - 1][0] - A[j]);
    }
  }

  cout << dp[0][N - 1][0] << endl;
}