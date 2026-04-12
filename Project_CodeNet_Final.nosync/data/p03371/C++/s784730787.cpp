#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = LLONG_MAX;
  for(ll i = 0; x>=0 || y>=0; i++) {
    if(x<0 && y<0) ans = min(ans, 2*i*c);
    else if(x<0) ans = min(ans,b*y+2*i*c);
    else if(y<0) ans = min(ans,a*x+2*i*c);
    else ans = min(ans,a*x+b*y+2*i*c);
    x--;
    y--;
  }
  cout << ans << endl;
  return 0;
}
