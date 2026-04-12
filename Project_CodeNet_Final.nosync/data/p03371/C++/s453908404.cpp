#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  // c*2でx++ y++となる。
  long long c_2 = 2 * c;
  long long ans = 1e10;
  for (int i = 0; i <= max(x, y); i++) {
    long long sum = 0;
    sum += c_2 * i;
    if (x - i > 0) {
      sum += a * (x - i);
    }
    if (y - i > 0) {
      sum += b * (y - i);
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
}
