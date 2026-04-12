#include <bits/stdc++.h>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a,b,c,x,y;
  cin >> a >> b>>c>>x>>y;

  int ans = 0;
  int ab = min(x, y);
  ans += ab * min(a+b, c*2);
  ans += (x - ab) * min(2 * c, a);
  ans += (y - ab) * min(2 * c, b);
  cout << ans << "\n";
}
