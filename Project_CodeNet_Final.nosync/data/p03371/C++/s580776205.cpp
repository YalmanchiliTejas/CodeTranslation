#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans = a*x+b*y;
  if(x<y) ans = min(ans,2*c*x+b*(y-x));
  else ans = min(ans,2*c*y+a*(x-y));
  ans = min(ans,2*c*max(x,y));
  cout << ans << endl;
}