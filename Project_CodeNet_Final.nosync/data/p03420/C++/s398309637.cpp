#include <stdio.h>

typedef long long ll;

int main(void) {
  ll n, k, ans = 0, i, j;
  scanf("%lld%lld", &n, &k);
  for(i = k + 1; i <= n; ++i) {
    ans += (n / i) * (i - k);
    if((n -(n / i) * i) - k + 1 > 0) ans += (n -(n / i) * i) - k + 1;
    if(!k) --ans;
    //printf("%lld\n", ans);
  }
  printf("%lld", ans);
  return 0;
}