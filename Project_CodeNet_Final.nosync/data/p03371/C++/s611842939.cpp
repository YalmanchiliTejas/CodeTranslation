#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = 100100100;
const double PI = 3.14159265358979323846;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)

int main() {
  ll a, b, c, x, y, ans = 0;
  cin >> a >> b >> c >> x >> y;
  if (a > 2 * c) a = 2 * c;
  if (b > 2 * c) b = 2 * c;
  ll lowerPrice = min(a + b, 2 * c);
  ll lessPizza = min(x, y);
  ll morePizza = max(x, y);
  ans += lowerPrice * lessPizza;
  if (lessPizza == x) ans += b * (morePizza - lessPizza);
  if (lessPizza == y) ans += a * (morePizza - lessPizza);
  cout << ans << endl;
  return 0;
}