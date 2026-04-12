#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if (a + b <= 2*c) {
    cout << x * a + y * b << '\n';
  }
  else {
    if (x < y) {
      cout << min(2 * y * c, (y-x) * b + x*2*c) << '\n';
    }
    else {
      cout << min(2 * x * c, (x-y) * a + y * 2 * c) << '\n';
    }
  }
}
