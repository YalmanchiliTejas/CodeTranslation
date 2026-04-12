#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) {
    cin >> a;
  }
  vector<vector<long long>> dp(N + 5, vector<long long>(N + 5));
  for (int i = N - 1; i >= 0; i--) {
    for (int j = i; j < N; j++) {
      if ((N - j + i) % 2) {
        if (i == j) {
          dp[i][j] = A[i];
        } else {
          dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j]);
        }
      } else {
        if (i == j) {
          dp[i][j] = -A[i];
        } else {
          dp[i][j] = min(dp[i + 1][j] - A[i], dp[i][j - 1] - A[j]);
        }
      }
    }
  }
  cout << dp[0][N - 1] << endl;

  return 0;
}
/* vim:set fdm=marker: */
