#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
  int a, b, c, x, y, sum_0, sum_1, sum_2, ans;
  cin >> a >> b >> c >> x >> y;
  sum_0 = a * x + b * y;
  if (x > y) sum_1 = y * c * 2 + (x - y) * a;
  else sum_1 = x * c * 2 + (y - x) * b;
  sum_2 = c * max(x, y) * 2;
  ans = min(sum_0, sum_1);
  ans = min(ans, sum_2);
  cout << ans << endl;
  return 0;
}
