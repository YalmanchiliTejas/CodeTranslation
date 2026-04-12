#include <bits/stdc++.h>
using namespace std;

long long a, b, c, x, y;

long long solve();

int main() {
  cin >> a >> b >> c >> x >> y;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = a * x + b * y;
  c *= 2;
  ans =
      min(ans, min(x, y) * c + (x - min(x, y)) * min(a, c) +
                   (y - min(x, y)) * min(b, c));
  return ans;
}