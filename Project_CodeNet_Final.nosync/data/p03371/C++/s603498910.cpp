#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int ans;
  if (a + b > c * 2) {
    ans = min(x,y) * c * 2;
    if (x > y) {
      ans += min(a * (x - y), 2 * c * (x - y));
    }
    else {
      ans += min(b * (y - x), 2 * c * (y - x));
    }
  }
  else {
    ans = a * x + b * y;
  }
  cout << ans << endl;
}
