#include <stdio.h>
#define mod 998244353
typedef long long ll;

int main(void) {
  ll i, j, k, n, s, ans = 0;
  scanf("%lld%lld", &n, &s);
  ll a, dp[s];
  for(i = 0; i < s; ++i) dp[i] = 0;
  dp[0] = 1;
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    if(s >= a) ans += dp[s - a] * (n - i), ans %= mod;
    if(a < s) for(j = s - a - 1; j >= 0; --j) dp[j + a] += dp[j], dp[j + a] %= mod;
    dp[0]++;
  }
  printf("%lld", ans);
  return 0;
}