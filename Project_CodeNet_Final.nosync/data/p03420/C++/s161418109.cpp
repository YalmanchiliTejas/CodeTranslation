#include <algorithm>
#include <cstdio>
typedef long long LL;
inline int f(int n, int b, int k) {
  return (n / b) * (b - k) + std::max(n % b - k + 1, 0);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  LL ans = 0;
  for (int b = k + 1; b <= n; ++b) ans += f(n, b, k);
  if (!k) ans -= n;
  printf("%lld\n", ans);
  return 0;
}
