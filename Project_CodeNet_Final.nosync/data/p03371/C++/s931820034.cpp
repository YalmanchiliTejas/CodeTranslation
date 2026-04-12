#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000000;

int main()
{
  int A, B, C, X, Y; scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
  ll ans = 1LL * A * X + B * Y;

  ll val = X * (2 * C) + max(0, Y - X) * B;
  ans = min(ans, val);
  val = Y * (2 * C) + max(0, X - Y) * A;
  ans = min(ans, val);
  printf("%lld\n", ans);
  return 0;
}
