#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, x, y, p1, p2, p3;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

  int mi = min(x, y), ma = max(x, y);
  p1 = a * x + b * y;
  p2 = mi * 2 * c + (ma - mi) * (ma == x ? a : b);
  p3 = ma * 2 * c;
  printf("%d\n", min(p1, min(p2, p3)));
  return 0;
}
