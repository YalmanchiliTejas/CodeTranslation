#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 60;

ll n,m,k;
ll mem;
ll ans;

ll factorial(ll n,ll mod = mod){
  static ll dp[e5];
  if(dp[n]) return dp[n];
  if(n == 0) return dp[n] = 1;
  return dp[n] = (n*factorial(n-1))%mod;
}

ll powl(ll x,ll r,ll mod = mod){
  ll ret = 1;
  for(;r != 0;r >>= 1){
    if(r&1 != 0) ret *= x,ret %= mod;
    x *= x,x %= mod;
  }
  return ret;
}

ll inverse(ll x,ll mod = mod){
  return powl(x,mod-2,mod);
}

ll combination(ll n,ll m,ll mod = mod){
  if(n < m) return 0;
  return (((factorial(n)*inverse(factorial(m)))%mod)*inverse(factorial(n-m)))%mod;
}

int main(){
  cin >> n >> m >> k;
  // for(ll i = 0;i < n;i++){
  //   for(ll j = 0;j < m;j++){
  //     mem += i*(i+1)/2*m+j*(j+1)/2*n;
  //     mem += (n-i)*(n-i-1)/2*m+(m-j)*(m-j-1)/2*n;
  //     mem %= mod;
  //   }
  // }
  ll mem = ((n-1)*n*(2*n-1)/6+n*(n-1)/2)/2*m*m + ((m-1)*m*(2*m-1)/6+m*(m-1)/2)/2*n*n;
  mem %= mod;
  ans = mem * k;
  ans %= mod;
  ans %= mod;
  ans *= inverse(n*m);
  ans %= mod;
  ans *= k-1;
  ans %= mod;
  ans *= inverse(n*m-1);
  ans %= mod;
  ans *= combination(n*m,k);
  ans %= mod;
  cout << ans << endl;



}
