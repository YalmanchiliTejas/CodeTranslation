#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

ll power(int k,int n,int M){
  if(n==0) return 1;
  if(n==1) return (ll)k;
  
  ll ret = power(k,n/2,M);
  
  ret=(ret*ret)%M;
  
  if(n%2==1) ret=(ret*k)%M;
  
  return ret;
}

ll power_memo[4010];

ll C(ll d, int m){
  ll res = 1;

  for(int i=0;i<m;i++){
    res = (res * ((d-i)%mod))%mod;
    res = (res * power_memo[i+1])%mod;
  }

  return res;
}

void solve(int n, ll d, int x){
  ll dp[4010] = {};
  ll res[2010] = {};
  
  dp[0] = 1;

  for(int i=0;i<n;i++){
    ll add[4010] = {};
    
    for(int j=0;j<n;j++){
      add[j+x] = -dp[j];
    }

    for(int j=n;j>0;j--){
      dp[j] = (mod + dp[j-1] + add[j])%mod;
    }
    dp[0] = 0;
      
    for(int j=0;j<n;j++){
      dp[j+1] = (dp[j+1] + dp[j])%mod;
    }

    res[i+1] = dp[n]%mod;
    dp[n] = 0;
  }

  ll ans = 0;
  
  for(int i=1;i<=min(d,(ll)n);i++){
    ans = (ans + res[i] * C(d, i) % mod)%mod;
  }

  printf("%lld\n",ans);
}

int main(){

  int n,x;
  ll d;

  for(int i=0;i<2010;i++){
    power_memo[i] = power(i, mod-2, mod);
  }
  
  while(1){
    scanf("%d%lld%d",&n,&d,&x);

    if(n == 0) break;

    solve(n,d,x);
  }
  
  return 0;
}