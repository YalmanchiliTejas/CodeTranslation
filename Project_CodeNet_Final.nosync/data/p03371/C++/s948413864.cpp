#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000000;

int main()
{
  ll A, B, C, X, Y; scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &X, &Y);
  ll ans = A * X + B * Y;
  ans = min(ans, 2 * X * C + B * max(Y - X, 0LL));
  ans = min(ans, 2 * Y * C + A * max(X - Y, 0LL));
  printf("%lld\n", ans);
  return 0;
}
