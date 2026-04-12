#include <cstdio>
#include <algorithm>
using std::min;
using std::max;
int n, k;
long long ans;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; j += i) {
      int st = max(j + k, 1), ed = min(j + i - 1, n);
      if (st <= ed) ans += ed - st + 1;
    }
  }
  printf("%lld", ans);
}
