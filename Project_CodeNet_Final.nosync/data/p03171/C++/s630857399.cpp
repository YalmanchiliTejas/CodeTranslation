#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
long long dp[N][N][2];
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    dp[i][i][0] = a[i];
    dp[i][i][1] = -a[i];
  }
  for (int r = 1; r < n; ++r) {
    for (int l = r - 1; l >= 0; --l) {
      dp[l][r][0] = max(a[l] + dp[l + 1][r][1], dp[l][r - 1][1] + a[r]);
      dp[l][r][1] = min(-a[l] + dp[l + 1][r][0], dp[l][r - 1][0] - a[r]);
    }
  }
  cout << dp[0][n - 1][0];

  return 0;
}