#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  ll ans = min(a*x+b*y, max(x, y)*2*c);
  ans = min(ans, min(x*2*c+(max(y-x, 0LL)*b), y*2*c+(max(x-y, 0LL)*a)));
  cout << ans << endl;
}
