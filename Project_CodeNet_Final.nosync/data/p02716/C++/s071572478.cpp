#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmax(T &a, T b) { /* {{{ */
  if (a < b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N;
  cin >> N;
  vector<long long> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  // 0: -1個，使わない
  // 1: -1個，使う
  // 2: +1個，使わない
  // 3: +1個，使う
  vector<vector<long long>> dp(N + 5, vector<long long>(4, -1e15));
  dp[0].assign(4, 0);
  for (int i = 1; i <= N; i++) {
    if (i % 2) {
      chmax(dp[i][0], max(dp[i - 1][2], dp[i - 1][3]));
      if (i >= 2) chmax(dp[i][1], max(dp[i - 2][0], dp[i - 2][1]) + A[i]);
      dp[i][2] = 0;
      chmax(dp[i][3], dp[i - 1][2] + A[i]);
    } else {
      chmax(dp[i][0], max(dp[i - 1][0], dp[i - 1][1]));
      if (i >= 2) chmax(dp[i][1], max(dp[i - 2][0], dp[i - 2][1]) + A[i]);
      chmax(dp[i][2], dp[i - 1][3]);
      chmax(dp[i][3], dp[i - 1][0] + A[i]);
    }
  }
  long long ans;
  if (N % 2) {
    ans = max(dp[N][0], dp[N][1]);
  } else {
    ans = max(dp[N][2], dp[N][3]);
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
