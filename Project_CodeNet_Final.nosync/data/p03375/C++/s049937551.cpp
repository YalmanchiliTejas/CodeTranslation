#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

ll n,m;

ll comb[3252][3252];  // combination
ll dstr[3252][3252];  // n items into k groups (distinct, may not use all n items)

// a^b mod m
ll modpow(ll a, ll b, ll m){
  ll r=1ll;
  while(b){
    if(b&1)r=r*a%m;
    a=a*a%m;
    b>>=1;
  }
  return r;
}
// 2^(2^n) mod m
ll pow2pow2(ll n, ll m){
  ll ret = 2ll;
  while(n--){
    ret = ret*ret % m;
  }
  return ret;
}

int main(){
  cin>>n;
  cin>>m;
  // m = 1000000007ll;

  REP(i,3252)REP(j,3252){
    comb[i][j] = j>i ? 0ll : (j==i || j==0 ? 1ll : (comb[i-1][j-1] + comb[i-1][j])%m);
  }
  REP(i,3252)dstr[i][0] = 1ll;
  FOR(i,1,3252)FOR(j,1,3252){
    dstr[i][j] = (dstr[i-1][j]*(j+1) + dstr[i-1][j-1]) % m;
  }

  ll ans = 0;
  FOR(k,0,n+1){
    ll add = 0;
    ll ramens = modpow(2ll, n-k, m);
    ll ramenspowx = 1ll;  // ramens^x mod m
    FOR(x,0,k+1){
      add = (add + dstr[k][x] * ramenspowx) % m;
      ramenspowx = ramenspowx * ramens % m;
    }
    add = add * comb[n][k] % m;
    add = add * pow2pow2(n-k, m) % m;
    if(k%2==0){
      ans += add;
    }else{
      ans += m-add;
    }
    if(ans>=m)ans-=m;
  }
  cout<<ans<<endl;
  return 0;
}
