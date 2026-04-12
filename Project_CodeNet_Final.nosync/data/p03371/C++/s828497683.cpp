#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int sum1, sum2, sum3;
  sum1 = a * x + b * y;
  if (x > y)
    sum2 = c * 2 * y + (x - y) * a;
  else
    sum2 = c * 2 * x + (y - x) * b;
  sum3 = max(x, y) * 2 * c;
  cout << min({sum1, sum2, sum3}) << endl;
  return 0;
}
