#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
using namespace std;
 
int main() {
  ll a, b, c, x, y, ans=0;
  cin >> a >> b >> c >> x >> y;
  if(a + b > 2 * c) {
    ans += 2 * c * min(x, y);
    if(x < y) ans += (y - x) * b;
    else ans += (x - y) * a;
  }
  else{
    ans +=  a * x + b * y;
  }
  ans = min(ans, 2 * c * max(x, y));
  cout << ans;
}
