#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, n, ans = 0, now, max, m;
  scanf("%lld", &n);
  ll a[n];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]);
  bool b;
  while(1) {
    b = true;
    now = 0;
    for(i = 0; i < n; ++i) if(a[i] > 1000) b = false;
    if(b) break;
    for(i = 0; i < n; ++i) now += a[i] / (n + 1), a[i] %= n + 1;
    for(i = 0; i < n; ++i) a[i] += now;
    ans += now;
  }
  while(1) {
    b = true;
    now = 0;
    for(i = 0; i < n; ++i) if(a[i] >= n) b = false;
    if(b) break;
    max = 0;
    for(i = 0; i < n; ++i) if(max < a[i]) max = a[i], m = i;
    a[m] -= n + 1;
    for(i = 0; i < n; ++i) a[i]++;
    ans++;
  }
  printf("%lld", ans);
  return 0;
}