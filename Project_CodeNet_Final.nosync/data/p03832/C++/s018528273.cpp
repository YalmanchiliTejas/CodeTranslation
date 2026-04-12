#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,m,n) for(ll i=m;i<(ll)(n);i++)
typedef pair<int,long long> pint;
typedef long long ll;
const ll mod= 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

ll dp[1010][1010],fact[1010],invfact[1010],inv[1010];
int a,b,c,d;

ll comb(int n,int k){
  ll ret=fact[n]*invfact[k]%mod;
  return ret*invfact[n-k]%mod;
  }

ll rec(int k,int m){
  if(m<0)return 0;
  if(dp[k][m]!=-1)return dp[k][m];
  if(k==a-1)return m==0;
  ll ret=rec(k-1,m);
  int cnt=1,res=1;
  int mm=m;
  while(m>=k&&cnt<=d){
    res=res*comb(m,k)%mod;
    res=res*inv[cnt] %mod;
    if(cnt>=c)ret+=res*rec(k-1,m-k);
    ret%=mod;
    m-=k;
    cnt++;
    }
  return dp[k][mm]=ret;
  }

ll f(ll n){
  ll ret=1,k=mod-2;
  while(k>0){
    if(k%2)ret=ret*n %mod;
    n=n*n %mod;
    k/=2;
    }
  return ret;
  }

int main(){
  fact[0]=invfact[0]=inv[0]=1;
  rep(i,1010)inv[i+1]=f(i+1);
  rep(i,1010){
    fact[i+1]=fact[i]*(i+1) %mod;
    invfact[i+1]=invfact[i]*inv[i+1] %mod;
    }
  int n;
  cin>>n>>a>>b>>c>>d;
  rep(i,1010)rep(j,1010)dp[i][j]=-1;
  cout<<rec(b,n)<<endl;
  return 0;
  }