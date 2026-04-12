#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

  if (x > y) {
    swap(x, y);
    swap(a, b);
  }

  int ans = min(a + b, c * 2) * x;
  y -= x;
  ans += min(b, c * 2) * y;

  printf("%d\n", ans);

  return 0;
}