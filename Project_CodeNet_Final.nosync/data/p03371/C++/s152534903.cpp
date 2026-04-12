#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ll a, b, c, x, y;
  scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &x, &y);
  ll ans = a * x + b * y;
  if (x > y) {
    ans = min(ans, c * 2 * y + (x - y) * a);
    ans = min(ans, c * 2 * x);
  }
  else {
    ans = min(ans, c * 2 * x + (y - x) * b);
    ans = min(ans, c * 2 * y);
  }

  printf("%lld\n", ans);
  return 0;
}
