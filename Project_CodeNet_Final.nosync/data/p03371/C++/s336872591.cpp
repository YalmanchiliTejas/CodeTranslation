#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long ans = 0, d;
  if (2*c <= a + b) {
    ans += 2*c*min(x, y);
    if (x <= y) {
      ans += min(b*(y - x), 2*c*(y - x));
    }
    else {
      ans += min(a*(x - y), 2*c*(x - y));
    }
  }
  else {
    ans += a*x + b*y;
  }
  cout << ans << endl;
  return 0;
}