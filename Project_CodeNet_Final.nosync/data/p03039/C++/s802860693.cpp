#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007
#define MX 200005

ll fact[MX];
ll invfact[MX];

ll mod_pow(ll x, ll n, ll mod){
  if(n==0) return 1;
  ll res = mod_pow(x * x % mod, n / 2, mod);
  if(n & 1) res = res * x % mod;
  return res;
}
ll mod_comb(ll n, ll k, ll p){
  if(n<0 || k<0 || n<k) return 0;
  return (((fact[n] * invfact[k]) % MOD) * invfact[n-k]) % MOD;
}
void comb_init(){
  fact[0] = fact[1] = 1;
  for(ll i=2; i<MX; i++) fact[i] = (fact[i-1] * i) % MOD;
  invfact[0] = invfact[1] = 1;
  for(ll i=2; i<MX; i++) invfact[i] = mod_pow(fact[i], MOD-2, MOD);
}

int main(){
  comb_init();

  ll N, M, K;
  cin >> N >> M >> K;

  ll ret = 0;

  ll X = mod_comb(M*N-2, K-2, MOD);
  
  REP(i,1,M+1){
    ll tmp = (M-i);
    tmp *= N;
    tmp %= MOD;
    tmp *= N;
    tmp %= MOD;
    tmp *= i;
    tmp %= MOD;
    tmp *= X;
    tmp %= MOD;
    ret += tmp;
    ret %= MOD;
  }
  REP(i,1,N+1){
    ll tmp = (N-i);
    tmp *= M;
    tmp %= MOD;
    tmp *= M;
    tmp %= MOD;
    tmp *= i;
    tmp %= MOD;
    tmp *= X;
    tmp %= MOD;
    ret += tmp;
    ret %= MOD;
  }

  cout << ret << endl;
  
  return 0;
}

