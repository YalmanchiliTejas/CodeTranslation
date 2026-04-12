//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

template<typename integer>
integer __lcm(integer a, integer b) {
  return (a * b) / __gcd(a, b);
}

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  // a1枚 b1枚を買うために必要なコスト
  int d = min(a + b, 2 * c);
  int ans1 = 2 * c * max(x, y);

  int ans2 = 0;

  while (!(x == 0 && y == 0)) {
    // cout << x << ", " << y << endl;

    if (x >= 1 && y >= 1) {
      x--;
      y--;
      ans2 += d;
    }

    else if (x >= 1) {
      x--;
      ans2 += a;
    }

    else if (y >= 1) {
      y--;
      ans2 += b;
    }
  }

  cout << min(ans1, ans2) << endl;
  return 0;
}

