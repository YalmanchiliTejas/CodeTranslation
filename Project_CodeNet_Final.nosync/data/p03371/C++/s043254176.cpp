#include <algorithm>  //min, max, sort, unique, fill
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>  //pair, swap,
#include <vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using VI = vector<ll>;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) for (ll i = 0; i < (n); i++)

static const ll kIntMax = numeric_limits<ll>::infinity();
static const double kFloatMax = numeric_limits<double>::infinity();

vector<ll> vi;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll price = 0, tmp;
  price = 1000000000;
  REP(i, 100001) {
    tmp = i * c * 2 + max(0ll, x - i) * a + max(0ll, y - i) * b;
    if (tmp < price) price = tmp;
    if (i > x && i > y) break;
  }

  /*  if (a + b < c * 2)
      price = a * x + b * y;
    else {
      if (c * 2 <= a) {
        price += x * c * 2;
        y -= x;
        x = 0;
        // cerr << "price:" << price << "x:" << x << "y:" << y << endl;
      }

      if (c * 2 <= b && y > 0) {
        price += y * c * 2;
        x -= y;
        y = 0;
        // cerr << "price:" << price << "x:" << x << "y:" << y << endl;
      }

      x = max(0ll, x);
      y = max(0ll, y);

      ll z = ((ll)min(x, y) / 2) * 2;
      price += z * c * 2 + (x - z) * a + (y - z) * b;
      // cerr << "price:" << price << "x:" << x << "y:" << y << "z:" << z <<
    endl;
    }
  */
  cout << price << endl;

  return 0;
}
