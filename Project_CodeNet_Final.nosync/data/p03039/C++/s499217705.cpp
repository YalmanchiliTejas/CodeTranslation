//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
//const ll MOD=998244353LL;
//const ll MAX_V=114514LL;
const ll MAX = 510000LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
  COMinit();
  ll n,m,k;cin>>n>>m>>k;
  ll ans=0;
  
  for(ll i=1;i<=n-1;i++){
    ll part=COM(n*m-2,k-2);
    part*=n-i;
    part%=MOD;
    part*=m;
    part%=MOD;
    part*=m;
    part%=MOD;
    part*=i;
    part%=MOD;
    ans+=part;
    ans%=MOD;
  }
  //cout<<ans<<endl;
  for(ll i=1;i<=m-1;i++){
    ll part=COM(n*m-2,k-2);
    part*=m-i;
    part%=MOD;
    part*=n;
    part%=MOD;
    part*=n;
    part%=MOD;
    part*=i;
    part%=MOD;
    ans+=part;
    ans%=MOD;
  }
  cout<<ans<<endl;

}