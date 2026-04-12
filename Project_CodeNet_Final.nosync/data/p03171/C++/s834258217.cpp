#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll A[3005];
ll dp[3005][3005];

ll solve(int i, int j) {
  if (i > j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  dp[i][j] = max(A[i] - solve(i + 1, j), A[j] - solve(i, j - 1));
  return dp[i][j];
}

int main() {
  fill(&dp[0][0], &dp[0][0] + 3005 * 3005, -1);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  cout << solve(0, n - 1) << '\n';
  return 0;
}
