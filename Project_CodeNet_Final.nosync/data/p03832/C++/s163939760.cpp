#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

ll mod_pow(ll x,ll n){
  if(n==0) return 1;
  ll ret=1;
  ret = mod_pow((x*x)%MOD,n/2);
  if(n&1) ret = ret*x%MOD;
  return ret;
}

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
        return (fact[n]*finv[k]%mod)*finv[n-k]%mod;
    }
};

ll dp[1123][1123];
int main() {
  int N,A,B,C,D;
  cin >> N >> A >> B >> C >> D;
  ModCombination<MOD> comb(N);
  dp[A-1][0] = 1;
  for(int i=A;i<=B;i++){
    for(int j=0;j<=N;j++){
      dp[i][j] = dp[i-1][j];
      for(int k=C;k<=min(D,j/i);k++){
        ll c = (((((comb.Comb(N-j+i*k,i*k)*comb.fact[i*k])%MOD)*mod_pow(comb.finv[i],k))%MOD)*comb.finv[k])%MOD;
        dp[i][j] = (dp[i][j]+(c*dp[i-1][j-i*k])%MOD)%MOD;
      }
    }
  }
  cout << dp[B][N] << endl;
  return 0;
}
