#include <iostream>
using namespace std;

int main() {
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  int ans = 0;
  
  if (a + b <= c * 2) {
    ans = a * x + b * y;
  } else if (x == y) {
    ans = c * x * 2;
  } else if (x < y) {
    if (b >= c * 2) ans = c * x * 2 + (y - x) * c * 2;
    else ans = c * x * 2 + (y - x) * b;
  } else if (x > y) {
    if (a >= c * 2) ans = c * x * 2 + (y - x) * c * 2;
    else ans = c * y * 2 + (x - y) * a;
  }
  
  cout << ans << endl;
}