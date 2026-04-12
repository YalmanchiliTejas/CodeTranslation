#include <iostream>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

  int ans = 1e9;
  for(int i = 0; i <= max(x, y); ++i) {
    int sum_a = max((x-i)*a, 0);
    int sum_b = max((y-i)*b, 0);

    ans = min(ans, i*2*c + sum_a + sum_b);
  }

  cout << ans << '\n';
  return 0;
}
