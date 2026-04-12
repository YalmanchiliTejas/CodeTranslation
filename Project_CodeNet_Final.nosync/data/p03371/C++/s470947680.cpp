#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;

  cin >> a >> b >> c >> x >> y;

  c *= 2;

  int ans = INT_MAX;

  for (int i = 0; i <= max(x, y); i++) {
    ans = min(ans, i * c + max(0, (x - i) * a) + max(0, (y - i) * b));
  }

  cout << ans;

  return 0;
}