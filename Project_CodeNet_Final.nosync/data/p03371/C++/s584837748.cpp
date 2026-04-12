#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, x, y, z, ans;
  scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &x, &y);
  z = max(x, y);
  ans = (long long)9e9;
  for (int i = 0; i <= z; i++) {
    ans = min(ans, a * max(0LL, (x - i)) + b * max(0LL, (y - i)) + 2 * c * i);
  }
  printf("%ld", ans);
  return 0;
}