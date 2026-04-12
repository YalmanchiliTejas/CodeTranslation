#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int mod = 1e9 + 7;

int main() {

  string K;
  int D;
  cin >> K >> D;
  vector<int> dp(D, 0);
  dp[0] = 1;
  int n = K.length();
  int ans = 0;
  vector<int> prefix_sum(n, 0);
  prefix_sum[0] = (K[0] - '0') % D;
  for (int i = 1; i < n; ++i) {
    prefix_sum[i] = (prefix_sum[i-1] + K[i] - '0') % D;
  }

  ans = (prefix_sum[n-1] == 0);
  for (int i = n - 1; i >= 0; --i) {
    int num = K[i] - '0';
    for (int j = (i == 0 ? 1: 0); j < num; ++j) {
      int d = (i == 0 ? 0 : prefix_sum[i-1]) + j;
      for (int r = 0; r < D; ++r) {
        if ((d + r) % D == 0) {
          ans += dp[r];
          if (ans >= mod) {
            ans -= mod;
          }
        }
      }
    }
    vector<int> new_dp(D, 0);
    for (int j = 0; j < D; ++j) {
      for (int d = 1; d <= 9; ++d) {
        int m = (j + d) % D;
        new_dp[m] += dp[j];
        if (new_dp[m] >= mod) {
          new_dp[m] -= mod;
        }
      }
    }
    if (i > 0) {
      ans += new_dp[0];
      if (ans >= mod) {
        ans -= mod;
      }
    }
    for (int j = 0; j < D; ++j) {
      new_dp[j] += dp[j];
      if (new_dp[j] >= mod) {
        new_dp[j] -= mod;
      }
    }
    dp = new_dp;
  }
  cout << ans << '\n';
  return 0;
}
