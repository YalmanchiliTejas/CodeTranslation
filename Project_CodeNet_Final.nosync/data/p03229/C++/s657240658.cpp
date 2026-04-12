#include <cstdio>
#include <algorithm>
#include <numeric>

int main()
{
  int n;
  scanf("%d", &n);
  long long a[100000];
  for (int i = 0; i < n; ++i)
  {
    scanf("%lld", a + i);
  }
  std::sort(a, a + n);
  long long ans;
  if (n & 1)
  {
    ans = std::max
    (
      a[n / 2] + a[n / 2 + 1] + 2 * std::accumulate(a + (n / 2 + 2), a + n, 0LL) - 2 * std::accumulate(a, a + n / 2, 0LL),
      - 2 * std::accumulate(a, a + ((n + 1) / 2 - 2), 0LL) - a[(n + 1) / 2 - 2] - a[(n + 1) / 2 - 1] + 2 * std::accumulate(a + (n + 1) / 2, a + n, 0LL)
    );
  }
  else
  {
    ans = a[n / 2] + 2 * std::accumulate(a + (n / 2 + 1), a + n, 0LL) - 2 * std::accumulate(a, a + (n / 2 - 1), 0LL) - a[n / 2 - 1];
  }
  printf("%lld\n", ans);
  return 0;
}