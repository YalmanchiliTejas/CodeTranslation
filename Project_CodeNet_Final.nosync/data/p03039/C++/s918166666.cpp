#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll getPow(ll a,ll p){
  ll ret = 1,cp = a;
  while(p){
    if(p&1) ret = (ret*cp)%MOD;
    p >>= 1;
    cp = (cp*cp)%MOD;
  }
  return ret;
}
int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  ll t = n*m,ans = 0;
  ll n2 = (n*n)%MOD,m2 = (m*m)%MOD,t2 = 1,k2 = 1;
  for(int i = 1; i <= k-2; ++i){
    k2 = (k2*i)%MOD;
    t2 = (t2*(t-k+i))%MOD;
  }
  ll C = (t2*getPow(k2,MOD-2))%MOD;
  for(int d = 1; d < n; ++d){
    ans = (ans + ((d*(n-d))%MOD)*((m2*C)%MOD))%MOD;
  }
  for(int d = 1; d < m; ++d){
    ans = (ans + ((d*(m-d))%MOD)*((n2*C)%MOD))%MOD;
  }
  cout << ans;
  return 0;
}