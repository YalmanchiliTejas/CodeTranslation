#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
constexpr long long INF = (long long)1e18 + 10;

int main(){
  int N; cin >> N;
  vector<int> A(N); rep(i, N) cin >> A[i];
  vector<vector<long long>> dp(3, vector<long long>(N + 2, -INF));

  if (N % 2 == 0) {
    A.insert(A.begin(), 0);
    N++;
    dp[1][0] = 0;
  } else {
    dp[0][0] = 0;
  }

  rep(i, N) {
    if (i % 2 == 0) {
      dp[0][i + 1] = dp[0][i] + A[i];
      dp[1][i + 1] = max(dp[1][i], dp[0][i]);
      dp[2][i + 1] = max(dp[2][i] + A[i], dp[1][i]);
    } else {
      dp[0][i + 1] = dp[0][i];
      dp[1][i + 1] = max(dp[1][i] + A[i], dp[0][i]);
      dp[2][i + 1] = max(dp[2][i], dp[1][i]);
    }
  }

  cout << dp[2][N] << endl;
}
