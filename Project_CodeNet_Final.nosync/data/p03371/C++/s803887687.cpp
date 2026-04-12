#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 30;

// ===============================================================================

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int m = min(x, y);
  ll ans = 0;
  if (a + b > c * 2) {
    ans = c * m * 2;  // ABピザがお安いとき
  } else {
    ans = (a + b) * m;
  }

  x -= m;
  y -= m;

  if (x > 0) {  // Aビザがまだ必要
    if (a > c * 2) {
      ans += c * x * 2;
    } else {
      ans += a * x;
    }
  } else {
    if (b > c * 2) {
      ans += c * y * 2;
    } else {
      ans += b * y;
    }
  }

  cout << ans << endl;
}
