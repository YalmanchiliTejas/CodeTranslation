#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll a, b, c, x ,y;
ll k, ans;

int main() {
  cin >> a >> b >> c >> x >> y;
  ans = 0;
  if (a + b >= 2 * c) {
    k = min(x, y);
    x -= k; y -= k;
    ans += 2 * k * c;
  }
  if (a >= 2 * c) {
    ans += 2 * c * x;
    x = 0;
  }
  if (b >= 2 * c) {
    ans += 2 * c * y;
    y = 0;
  }
  ans += x * a + y * b;
  cout << ans << endl;
  return 0;
}
