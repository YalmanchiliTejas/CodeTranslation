#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n, ll x, ll m){
  ll ref = x;
  ll now = x * x % m;
  int cnt = 1;
  vector<ll> d(m+1);
  d[0] = 0;
  while(now != x){
    d[cnt] = ref;
    ref += now;
    now = now * now %m;
    ++cnt;
  }
  ref = n/cnt *ref + d[n%cnt];
  return ref;
}

int main(){
  ll n, x, m;
  cin >> n >> x >> m;
  vector<bool> ok(m,true);
  ll cnt = 0;
  ll ans = 0;
  while(cnt < n){
    if(!ok[x]) break;
    ans += x;
    ok[x] = false;
    x = x*x % m;
    ++cnt;
  }
  ans += f(n-cnt,x,m);
  cout << ans << endl;
}