#include <bits/stdc++.h>
using namespace std;

void ins(map<int, int> &ma, int k) {
  for (int i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      ++ma[i];
      if (k / i != i)
        ++ma[k / i];
    }
  }
}

void era(map<int, int> &ma, int k) {
  for (int i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      --ma[i];
      if (ma[i] == 0)
        ma.erase(i);
      if (k / i != i) {
        --ma[k / i];
        if (ma[k / i] == 0)
          ma.erase(k / i);
      }
    }
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k == 0)
    return 0 * printf("%lld\n", 1LL * n * n);
  map<int, int> divs;
  for (int i = 1; i <= k; ++i)
    ins(divs, i);
  long long x = 0;
  for (int i = 1; i + k - 1 <= n; ++i) {
    x -= divs.size();
    era(divs, i);
    if (i + k <= n)
      ins(divs, i + k);
  }
  long long ans = 0;
  for (int i = k; i < n; ++i)
    ans += n - i;
  ans -= 1LL * (k - 1) * k / 2;
  for (int i = 1; i <= n; ++i)
    x += i;
  printf("%lld\n", ans + x);
  return 0;
}