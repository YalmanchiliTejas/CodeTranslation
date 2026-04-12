#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,x0,m;
  cin >> n >> x0 >> m;
  auto f = [&](ll x){return (x*x)%m;};

  if(n<=m){
    ll ans = 0, x = x0;
    rep(_,n){
      ans += x;
      x = f(x);
    }
    cout << ans << endl;
    return 0;
  }

  vector<ll> s(m,-1),d(m,-1);
  ll si=0,di=0;
  ll x=x0;
  while(d[x]<0){
    si+=x;
    s[x] = si;
    d[x] = di;
    x = f(x);
    ++di;
  }
  // cout << x << endl;
  // rep(i,m) cout << d[i] << " "; cout << di << endl;
  // rep(i,m) cout << s[i] << " "; cout << si << endl;
  ll ans = si;
  si+=x;
  n -= di;

  ans += (n/(di-d[x])) * (si-s[x]);
  n %= di-d[x];

  rep(_,n){
    ans += x;
    x = f(x);
  }
  cout << ans << endl;
}
