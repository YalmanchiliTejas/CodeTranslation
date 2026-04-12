#include <stdio.h>
#define mod 1000000007
typedef long long ll;

int main(void) {
  ll i, j, k, n, ans = 0;
  scanf("%lld", &n);
  ll a[n], dp[n][2];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), dp[i][0] = dp[i][1] = -1e18;
  dp[0][1] = 0, dp[1][1] = 0;
  dp[0][0] = a[0];
  dp[1][0] = a[0] > a[1] ? a[0] : a[1];
  for(i = 2; i < n; ++i) {
    if(i & 1) dp[i][0] = dp[i - 1][0], dp[i][1] = dp[i - 1][1];
    else dp[i][1] = dp[i - 1][0];
    if(dp[i][0] < dp[i - 2][0] + a[i]) dp[i][0] = dp[i - 2][0] + a[i];
    if(dp[i][1] < dp[i - 2][1] + a[i]) dp[i][1] = dp[i - 2][1] + a[i];
  }
  printf("%lld", dp[n - 1][n & 1]);
  return 0;
}