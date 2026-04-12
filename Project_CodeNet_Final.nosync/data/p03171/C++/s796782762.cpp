#include <bits/stdc++.h>

#define MAX_N 3000
typedef long long int ll;

int n;
ll a[MAX_N];

ll dp[MAX_N + 1][MAX_N + 1];

int main() {
  std::cin >> n;
  for(int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  for(int i = 0; i <= n; ++i) {
    dp[i][i] = 0;
  }
  for(int len = 1; len <= n; ++len) {
    for(int i = 0; i + len <= n; ++i) {
      int j = i + len;
      if((n - len) % 2 == 0) {
        dp[i][j] = std::max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
      } else {
        dp[i][j] = std::min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
      }
    }
  }

  std::cout << dp[0][n] << std::endl;
}
