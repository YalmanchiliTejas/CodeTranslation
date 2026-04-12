#include <bits/stdc++.h>
#define FOR(i,k,n)  for(ll i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;
constexpr ll MOD = 1000000007;

// a^-1 mod p
ll inv(ll a,ll p){
  return ( a == 1 ? 1 : (1 - p*inv(p%a,a)) / a + p );
}

int main()
{
  ll f[300000];
  ll invf[300000];
  f[0] = invf[0] = 1;
  REP(i,200000) {
    f[i+1] = f[i] * (i+1);
    f[i+1] %= MOD;
    invf[i+1] = inv(f[i+1], MOD);
  }
  ll n,m,k;
  cin>>n>>m>>k;
  ll nm = n*m;
  ll coeff = f[nm-2] * invf[k-2] % MOD * invf[nm - k] % MOD;
  ll res = 0;
  REP(r,n) {
    REP(c,m) {
      ll rc = m-c-1;
      ll cc = c*(c+1)/2 + rc*(rc+1)/2;
      cc %= MOD;
      cc *= n;
      cc %= MOD;
      ll rr = n-r-1;
      ll cr = r*(r+1)/2 + rr*(rr+1)/2;
      cr %= MOD;
      cr *= m;
      cr %= MOD;
      ll tmp = cc + cr;
      tmp %= MOD;
      res += tmp;
      res %= MOD;
    }
  }
  res *= coeff;
  res %= MOD;
  res *= inv(2, MOD);
  res %= MOD;
  cout << res << endl;
  return 0;
}
