#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  // 全部ばらばら
  int val1 = a * x + b * y;
  // Aをできる限りABで
  int val2 = c * 2 * x + b * max(0, y - x);
  // Bをできる限りABで
  int val3 = c * 2 * y + a * max(0, x - y);
  cout << min(min(val1, val2), val3) << endl;

  return 0;
}
