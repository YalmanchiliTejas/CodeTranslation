#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll gya[200010];
ll kai[200010];
ll beki(ll n,ll k){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=mod;
    }
    now*=now;
    now%=mod;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n){
  return beki(n,mod-2);
}
void nckinit(ll n){
  kai[0]=1;
  kai[1]=1;
  for(int i=2;i<=n;i++){
    kai[i]=kai[i-1]*i;
    kai[i]%=mod;
  }
  gya[n]=gyaku(kai[n]);
  for(int i=n-1;i>=1;i--){
    gya[i]=gya[i+1]*(i+1);
    gya[i]%=mod;
  }
  gya[0]=1;
}    
ll nck(ll n,ll k){
  if(k<0)return 0;
  if(k==0||n==k)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=mod;
  ret*=gya[k];
  ret%=mod;
  return ret;
}
ll npk(ll n,ll k){
  if(k<0)return 0;
  if(k==0)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=mod;
  return ret;
}

int main(){
  
  string s;cin>>s;
  ll d;cin>>d;
  ll n=s.size();
  ll dp[n+1][d][2];
  memset(dp,0,sizeof dp);
  dp[0][0][1]=1;
  rep(i,0,n){
    rep(j,0,d){
      rep(k,0,10){
        int uu=s[i]-'0';
        (dp[i+1][(j+k)%d][0]+=dp[i][j][0])%=mod;
        if(k<uu)(dp[i+1][(j+k)%d][0]+=dp[i][j][1])%=mod;
        if(k==uu)(dp[i+1][(j+k)%d][1]+=dp[i][j][1])%=mod;
      }
    }
  }
  cout<<(dp[n][0][0]+dp[n][0][1]-1+mod)%mod<<endl;
  
}
      
