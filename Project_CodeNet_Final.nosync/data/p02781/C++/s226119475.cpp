#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string N;
  cin >> N;
  int n = N.length();
  int K;
  cin >> K;
  long long dp[n + 1][K + 1];
  int cnt = 0;
  fill(dp[0], dp[0] + K + 1, 0);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for (int k = 1; k <= K; k++) {
      dp[i][k] = dp[i - 1][k];
      if (cnt == k - 1) {
        dp[i][k] += 9 * (dp[i - 1][k - 1] - 1) + (N[i - 1] - '0');
      } else {
        dp[i][k] += 9 * dp[i - 1][k - 1];
      }
    }
    cnt += N[i - 1] > '0';
  }
  cout << dp[n][K] << endl;
  return 0;
}
