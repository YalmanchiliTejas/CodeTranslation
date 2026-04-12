#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e3 + 5;

ll a[N];
ll dp[N][N][2];

ll solve(int i, int j, int p) {
  if (j < i)
    return 0;
  if (dp[i][j][p] != -1)
    return dp[i][j][p];
  
  if (p) {
    dp[i][j][p] = max(solve(i+1, j, !p) + a[i],
                      solve(i, j-1, !p) + a[j]);
  } else {
    dp[i][j][p] = min(solve(i+1, j, !p) - a[i],
                      solve(i, j-1, !p) - a[j]);
  }
  return dp[i][j][p];
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      dp[i][j][0] = dp[i][j][1] = -1;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << solve(0, n-1, 1) << '\n';
  return 0;
}