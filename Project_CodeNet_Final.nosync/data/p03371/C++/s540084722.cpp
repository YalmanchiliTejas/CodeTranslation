#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int ans = 0;
  int min_xy = min(x, y);
  if (a + b > 2 * c) {
    ans +=  2 * c * min_xy;
  } else {
    ans += (a + b) * min_xy;
  }
  x -= min_xy; y -= min_xy;
  
  if (x > 0) ans += min(a, 2 * c) * x;
  if (y > 0) ans += min(b, 2 * c) * y;
  
  cout << ans << endl;
  return 0;
}
