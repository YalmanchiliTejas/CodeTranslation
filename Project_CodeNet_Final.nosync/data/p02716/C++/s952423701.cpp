#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 202020;
constexpr long long INF = 1LL << 60;
long long dp[N][5][2];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) for (int j = 0; j < 5; j++) {
    dp[i][j][0] = dp[i][j][1] = -INF;
  }
  dp[0][2][0] = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    //use;
    for (int j = 0; j < 5; j++) {
      int num = (i - 1) / 2 + (j - 2);
      for (int k = 0; k < 5; k++) {
        int num_nxt = i / 2 + (k - 2);
        if (num + 1 != num_nxt) continue;
        dp[i][k][1] = max(dp[i][k][1], dp[i - 1][j][0] + a);
      }
    }
    //not use;
    for (int j = 0; j < 5; j++) {
      int num = (i - 1) / 2 + (j - 2);
      for (int k = 0; k < 5; k++) {
        int num_nxt = i / 2 + (k - 2);
        if (num != num_nxt) continue;
        dp[i][k][0] = max({dp[i][k][0], dp[i - 1][j][1], dp[i - 1][j][0]});
      }
    }
  }
  cout << max(dp[n][2][0], dp[n][2][1]) << endl;
  return 0;
}