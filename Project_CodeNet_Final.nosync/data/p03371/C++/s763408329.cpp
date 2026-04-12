#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                      \
  ifstream in("loadtolb/arc096_a.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;

  ll ans = 0;
  // 1. abを使う
  if (a + b > c) {
    int z = min(x, y);
    ans += z * c;
    x -= z;
    y -= z;

    if (x != 0) {
      ans += min(x * a, x * c);
    } else {
      ans += min(y * b, y * c);
    }

  } else {
    ans += a * x;
    ans += b * y;
  }

  cout << ans << endl;
}