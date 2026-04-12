#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  if (a + b <= 2 * c) {
    cout << a * x + b * y << endl;
  }
  else {
    int ans = 0;
    if (x < y) {
      swap(a, b);
      swap(x, y);
    }
    ans += c * 2 * y;
    x -= y;
    if (a <= 2 * c) {
      ans += a * x;
    }
    else {
      ans += c * 2 * x;
    }
    cout << ans << endl;
  }

  
  return 0;
}