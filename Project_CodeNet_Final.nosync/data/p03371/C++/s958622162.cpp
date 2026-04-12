#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y, price = 0;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  price = min(a*x + b*y, 2*c*max(x, y));
  int z = x < y? b: a;
  price = min(price, 2*c*min(x, y) + z*abs(x - y));
  printf("%d", price);
}