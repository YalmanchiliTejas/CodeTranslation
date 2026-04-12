#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600
#define MOD 1000000007
#define long long long

// x^n mod
long mod_pow(long x, long n, long mod){
  long res=1;
  x %= mod;
  while(n>0){
    if(n&1) res=res*x%mod;
    x=x*x%mod;
    n>>=1;
  }
  return res;
}
long mod_inv(long x){ return mod_pow(x,MOD-2,MOD); }

long fact[1005];
long fact_inv[1005];
long inv[1005];
long comb(long n, long k){ return fact[n]*fact_inv[k]%MOD*fact_inv[n-k]%MOD; }

int main(){
  long n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  vector<vector<long>> dp(b+1, vector<long>(n+1,0));
  // dp[i][j] i人以下のグループのみからなる組み合わせをn人のうちのj人からつくる

  fact[0]=1;
  rep(i,1000) fact[i+1]=(i+1)*fact[i]%MOD;
  rep(i,1001) fact_inv[i]=mod_inv(fact[i]);
  rep(i,1001) inv[i]=mod_inv(i);

  dp[0][0]=1;
  rep(i,b) dp[i][0]=1;
  repl(i,a,b+1){
    repl(j,1,n+1){
      long tmp = 1;
      long x = n-j;
      dp[i][j] = dp[i-1][j];
      for(int k=1; k*i<=n; k++){
        if(k>d) break;
        if(j<i*k) break;
        x += i;
        tmp = tmp*comb(x,i)%MOD*inv[k]%MOD;
        if(k<c) continue;
        dp[i][j] += tmp*dp[i-1][j-i*k];
        dp[i][j] %= MOD;
      }
    }
  }
//  rep(i,b+1)dbg(dp[i]);

  cout<<dp[b][n]<<endl;

  return 0;
}
