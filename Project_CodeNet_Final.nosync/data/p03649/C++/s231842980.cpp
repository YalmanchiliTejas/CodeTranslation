#include <bits/stdc++.h>
using namespace std;
const int N = 55;
typedef long long ll;
ll a[N],s;
int n;
ll check(ll mid) {
  ll cnt = 0;
  for (int i = 1 ; i <= n ; ++ i)
    cnt += max(0ll,(a[i] - mid) / (n + 1));
  return cnt;
}
int main() {
  scanf("%d",&n);
  for (int i = 1 ; i <= n ; ++ i)
    scanf("%lld",&a[i]), s += a[i];
  s -= n * (n-1);
  if (s > 0) {
    ll mx = 0;
    for (int i = 1 ; i <= n ; ++ i)
      a[i] += s, mx = max(a[i],mx);
    ll l = 0, r = mx, ans, mid, tmp;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (check(mid) <= s) r = mid - 1, ans = mid, tmp = check(mid);
      else l = mid + 1;
    }
    for (int i = 1 ; i <= n ; ++ i) if (a[i] > ans)
      a[i] -= (a[i] - ans) / (n+1) * (n+1);
    for (int i = 1 ; i <= n ; ++ i)
      a[i] -= s - tmp;
    s = tmp;
  } else s = 0;
  while (true) {
    int pmx = 1;
    for (int i = 2 ; i <= n ; ++ i)
      if (a[i] > a[pmx]) pmx = i;
    if (a[pmx] < n) break;
    ++ s;
    for (int i = 1 ; i <= n ; ++ i)
      a[i] ++;
    a[pmx] -= n+1;
  }
  printf("%lld\n",s);
  return 0;
}