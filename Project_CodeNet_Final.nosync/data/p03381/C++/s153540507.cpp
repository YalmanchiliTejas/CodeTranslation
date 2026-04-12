#include <stdio.h>
#include <algorithm>
typedef long long ll;

int main(void) {
  ll i, j, k, n;
  scanf("%lld", &n);
  ll a[n], b[n];
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    b[i] = a[i];
  }
  std::sort(a, a + n);
  for(i = 0; i < n; ++i) {
    if(b[i] >= a[n / 2]) printf("%lld\n",a[n / 2 - 1]);
    else printf("%lld\n",a[n / 2]);
  }
  return 0;
}