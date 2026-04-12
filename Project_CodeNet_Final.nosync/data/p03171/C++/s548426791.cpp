#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000;
int dp[N + 5][N + 5][2];

int32_t main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  
  memset(dp, 0, sizeof dp);
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j + i <= n; ++j) {
      int l = j, r = i + j;
      if (dp[l+1][r][1] + a[l] > dp[l][r-1][1] + a[r]) {
        dp[l][r][0] = a[l] + dp[l+1][r][1];
        dp[l][r][1] = dp[l+1][r][0];
      } else {
        dp[l][r][0] = a[r] + dp[l][r-1][1];
        dp[l][r][1] = dp[l][r-1][0];
      }
    }
  }
  
  cout << dp[1][n][0] - dp[1][n][1] << '\n';
}