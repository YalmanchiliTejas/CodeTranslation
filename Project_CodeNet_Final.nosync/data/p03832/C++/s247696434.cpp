#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const ll longinf=1LL<<60;
const int mod=1000000007;    
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

ll pow(ll n,int k){
  if(k<0)k+=mod-1;
  ll ret=1;
  while(k>0){
    if(k&1)ret=ret*n %mod;
    n=n*n %mod;
    k>>=1;
    }
  return ret;
  }

int main(){
  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  ll fact[n+1];
  fact[0]=1;
  rep(i,n)fact[i+1]=(i+1)*fact[i]%mod;
  ll invfact[n+1];
  rep(i,n+1)invfact[i]=pow(fact[i],-1);
  ll dp[1001][1001];
  rep(i,n+1){
    dp[a-1][i]=0;
    }
  dp[a-1][0]=fact[n];
  REP(i,a,b+1){
    rep(j,n+1){
      dp[i][j]=dp[i-1][j];
      if(i*c<=j){
        int m=min(d-c+1,1+(j-i*c)/i);
        rep(k,m){
          ll res=dp[i-1][j-i*(c+k)]*pow(invfact[i],c+k)%mod;
          dp[i][j]+=res*invfact[c+k]%mod;
          }
        dp[i][j]%=mod;
        }
      }
    }
  cout<<dp[b][n]<<endl;
  return 0;
  }