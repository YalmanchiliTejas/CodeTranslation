#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans;
  if (x < y) {
    ans = min({a * x + b * y, 2 * c * x + b * (y - x), 2 * c * y});
  } else {
    ans = min({a * x + b * y, 2 * c * y + a * (x - y), 2 * c * x});
  }
  cout << ans << endl;
  return 0;
}