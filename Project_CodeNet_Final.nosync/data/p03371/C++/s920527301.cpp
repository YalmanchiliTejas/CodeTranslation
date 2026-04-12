#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y;

int ans;

int main(void){
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

  int ab = min(a + b, c * 2);

  if (x == y) {
    ans = x * ab;
  }
  else if (x > y) {
    ans = y * ab;
    int na = min(a, c * 2);
    ans += na * (x - y);
  }
  else if (x < y) {
    ans = x * ab;
    int nb = min(b, c * 2);
    ans += nb * (y - x);
  }

  printf("%d\n", ans);

  return 0;
}
