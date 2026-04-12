#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
long long dp[N][2][2];
int n;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        dp[i][j][k] = -1e18;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dp[0][0][0] = dp[0][1][0] = dp[0][0][1] = dp[0][1][1] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (!(j & k)) {
          for (int g = 0; g < 2; ++g) {
            for (int t = 0; t < 2; ++t) {
              int x = (i + 1) / 2 - g, y = i / 2 - t;
              if (y + j == x and y >= 0) {
                dp[i][g][j] = max(dp[i][g][j], dp[i - 1][t][k] + j * a[i]);
              }
            }
          }
        }
      }
    }
  }
  long long ans = -1e18;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      if ((i + 1) / 2 - j == n / 2) {
        for (int k = 0; k < 2; ++k) {
          ans = max(ans, dp[i][j][k]);
        }
      }
    }
  }
  cout << ans;

  return 0;
}