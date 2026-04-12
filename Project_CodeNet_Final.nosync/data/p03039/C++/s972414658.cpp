#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <float.h>
#include <random>

#define repeat(i,n) for (ll i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
#define debugArrayP(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge].first<< " " << x[hoge].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

template <ll mod>
struct ModCombination{
    ll N;
    vector<ll> fact,inv,finv;

    ModCombination(ll n):N(n){
        fact.assign(n+1, 1);
        inv.assign(n+1, 1);
        finv.assign(n+1,1);
        for(int i=1;i<n;i++){
            fact[i+1] = fact[i]*(i+1)%mod;
            inv[i+1] = inv[mod%(i+1)]*(mod-mod/(i+1))%mod;
            finv[i+1] = finv[i]*inv[i+1]%mod;
        }
    }

    ll Comb(ll n,ll k){
        if(k<0||n<k)return 0;
        return (fact[n]*finv[k]%mod)*finv[n-k]%mod;
    }
};

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

ll invMod(ll a, ll m) {
    ll x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    else                         return 0; // unsolvable
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N,M,K;cin>>N>>M>>K;
  ModCombination<MOD> C(N*M);
  ll ans=0;
  repeat(i,N){
    repeat(j,M){
      ll a = ((((((N*(((j*(j+1))%MOD+((M-j-1)*(M-j))%MOD)%MOD))%MOD+(M*(((i*(i+1))%MOD+((N-i-1)*(N-i))%MOD))%MOD)%MOD)%MOD))%MOD))%MOD;
      //debug(a);
      ans = (ans+a)%MOD;
    }
  }
  ans = (ans*invMod(4,MOD))%MOD;
  ans =(ans*C.Comb(N*M-2,K-2))%MOD;
  cout<<ans<<endl;
  return 0;
}
