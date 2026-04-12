#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

static ll p = 1000000007;

struct Combination{
  int MAX;
  ll MOD;
  vector<ll> fact;
  vector<ll> fact_inv;

  Combination(ll mod, ll max){
    MAX = max;
    MOD = mod;
    fact.resize(MAX);
    fact_inv.resize(MAX);
    fact[0] = 1;
    REP(i,MAX-1) fact[i+1] = fact[i]*(i+1)%MOD;
    fact_inv[MAX-1] = power(fact[MAX-1],MOD-2);
    for(ll i = MAX-2; i>=0; i--) fact_inv[i] = fact_inv[i+1]*(i+1)%MOD;
  }

  ll power(ll a, ll b){
    ll res=1;
  	while(b>0){
  		if(b&1) res=res*a%MOD;
  		a=a*a%MOD;
  		b>>=1;
  	}
  	return res;
  }

  ll comb(ll n, ll r){
	return (fact[n]*fact_inv[r])%MOD*fact_inv[n-r]%MOD;
}
};

int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  Combination com(p,250000);
  ll ans = 0;
  for(ll i=1;i<n;i++){
    ans += i*com.comb(n*m-2,k-2)*(n-i)%p*m%p*m%p;
    ans %= p;
  }
  for(ll i=1;i<m;i++){
    ans += i*com.comb(n*m-2,k-2)*(m-i)%p*n%p*n%p;
    ans %= p;
  }
  cout << ans << endl;
  return 0;
}
