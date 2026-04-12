#include <bits/stdc++.h>
using namespace std;

int main () {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long minPrice = INFINITY;
  for (int i = 0; i/2 <= max(x, y); i += 2) { //abピザをi枚買う
    int p, q;
    p = x - i / 2;
    q = y - i / 2;
    if (p < 0) p = 0;
    if (q < 0) q = 0;
    long long price = a*p + b*q + c*i;
    minPrice = min(minPrice, price);
  }
  cout << minPrice << endl;
}