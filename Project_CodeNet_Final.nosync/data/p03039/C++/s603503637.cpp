//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define MOD 1000000007
ll fac[1000000];
ll finv[1000000];
ll inv[1000000];

void comb_init(){
  fac[0] = 1;
  fac[1] = 1;
  for(int i=2;i<1000000;i++){
    fac[i] = i*fac[i-1];
    fac[i] %= MOD;
  }
  inv[1] = 1;
  for(int i=2;i<1000000;i++){
    inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
  }
  finv[0] = 1;
  finv[1] = 1;
  for(int i=2;i<1000000;i++){
    finv[i] = inv[i]*finv[i-1];
    finv[i] %= MOD;
  }
}

ll comb(ll n,ll k){
  ll c;
  c = fac[n];
  c *= finv[k];
  c %= MOD;
  c *= finv[n-k];
  c %= MOD;
  return c;
}

int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  ll ans = 0;
  ll x = 0;
  comb_init();
  ll c = comb(n*m-2,k-2);
  //cout << c << endl;
  for(int d=1;d<m;d++){
    x = 1;
    x *= n%MOD;
    x %= MOD;
    x *= n%MOD;
    x %= MOD;
    x *= d%MOD;
    x %= MOD;
    x *= (m-d)%MOD;
    x %= MOD;
    ans += x;
    ans %= MOD;
  }
  ll y = 0;
  for(int d=1;d<n;d++){
    y = 1;
    y *= m%MOD;
    y %= MOD;
    y *= m%MOD;
    y %= MOD;
    y *= d%MOD;
    y %= MOD;
    y *= (n-d)%MOD;
    y %= MOD;
    ans += y;
    ans %= MOD;
  }
  ans *= c;
  cout << ans%MOD << endl;

  return 0;
}
