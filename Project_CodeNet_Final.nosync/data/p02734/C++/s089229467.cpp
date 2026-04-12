#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

const int MOD_VAL = 998244353;

int main() {
  int n, s;
  cin >> n >> s;

  int arr[n];
  rep(i, n) cin >> arr[i];

  int dp[n + 1][s + 1];
  rep(i, n + 1) rep(j, s + 1) dp[i][j] = 0;
  dp[0][0] = 1;

  int ans = 0;
  rep(i, n) {
    rep(j, s + 1) dp[i + 1][j] = dp[i][j];
    rep(j, s) {
      // if (arr[i] + j <= s) dp[i + 1][arr[i] + j] += dp[i][j];
      if (arr[i] + j <= s) {
        dp[i + 1][arr[i] + j] = (dp[i + 1][arr[i] + j] + dp[i][j]) % MOD_VAL;
      }
    }
    dp[i + 1][0] = dp[i][0] + 1;
    ans = (ans + dp[i + 1][s]) % MOD_VAL;
  }
  cout << ans << endl;
  return 0;
}
