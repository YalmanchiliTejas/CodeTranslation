#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

ll mod,fact[3030],invfact[3030],p[3030],pp[3030],dp[3030][3030];

ll pow(ll n,ll k){
  ll ret=1;
  while(k>0){
    if(k&1)ret=ret*n %mod;
    n=n*n%mod;
    k/=2;
    }
  return ret;
  }

ll comb(int n,int k){
  ll ret=fact[n]*invfact[n-k]%mod;
  return ret*invfact[k] %mod;
  }

int main(){
  int n;cin>>n;
  cin>>mod;
  
  fact[0]=invfact[0]=1;
  pp[0]=2;
  rep(i,3000){
    fact[i+1]=(ll)(i+1)*fact[i] %mod;
    invfact[i+1]=pow(fact[i+1],mod-2);
    pp[i+1]=pp[i]*pp[i] %mod;
    }
  
  rep(i,n+1)dp[0][i]=0;
  dp[0][0]=1;
  REP(i,1,n+1)rep(j,n+1){
    if(j==0)dp[i][j]=1;
    else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*(j+1))%mod;
    }
  ll ans=0;
  rep(i,n+1){
    ll ret=0;
    rep(j,i+1){
      ll res=pow(2,(ll)(n-i)*j)*pp[n-i]%mod;
      res=res*dp[i][j]%mod;
      ret=(ret+res)%mod;
      }
    ret=ret*comb(n,i)%mod;
    if(i&1)ans+=mod-ret;
    else ans+=ret;
    ans%=mod;
    }
  cout<<ans<<endl;
  return 0;
  }