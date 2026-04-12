#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e15;

int main() {
  int N, K;
  cin >> N;
  K = 1 + N % 2;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<vector<ll>> dp(N + 1, vector<ll>(K + 2, -INF));

  dp[0][0] = 0;
  for (int i = 0; i <= N - 1; i++) {
    for (int j = 0; j <= K; j++) {
      dp[i + 1][j + 1] = dp[i][j];
      ll now = dp[i][j];
      if ((i + j) % 2 == 0) now += A[i];
      dp[i + 1][j] = max(dp[i + 1][j], now);
    }
  }
  cout << dp[N][K] << endl;
}
