#include <bits/stdc++.h>
using namespace std;

int main () {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long minPrice = INFINITY;
  for (int r = 0; r/2 <= max(x, y); r += 2) {
    int p = x - r/2;
    int q = y - r/2;
    if (p < 0) p = 0;
    if (q < 0) q = 0;
    long long price = p*a + q*b + r*c;
    minPrice = min(minPrice, price);
  }
  cout << minPrice << endl;
}