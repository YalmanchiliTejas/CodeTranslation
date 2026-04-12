#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=acos(-1.0);
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
    if(b==0)return a;
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
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
ll gya[1000010];
ll kai[1000010];

void nckinit(ll n,ll md){
  kai[0]=1;
  kai[1]=1;
  for(int i=2;i<=n;i++){
    kai[i]=kai[i-1]*i;
    kai[i]%=md;
  }
  gya[n]=gyaku(kai[n],md);
  for(ll i=n-1;i>=1;i--){
    gya[i]=gya[i+1]*(i+1);
    gya[i]%=md;
  }
  gya[0]=1;
}
ll nck(ll n,ll k,ll md){
  if(k<0)return 0;
  if(k==0||n==k)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=md;
  ret*=gya[k];
  ret%=md;
  return ret;
}
ll npk(ll n,ll k,ll md){
  if(k<0)return 0;
  if(k==0)return 1;
  ll ret=kai[n];
  ret*=gya[n-k];
  ret%=md;
  return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    ll dp[n+1][n+1];
    memset(dp,0,sizeof dp);
    nckinit(n+1,mod);
    dp[a-1][0]=1;
    rep(i,a,b+1){
        rep(j,0,n+1){
            if(dp[i-1][j]==0)continue;
            (dp[i][j]+=dp[i-1][j])%=mod;
            ll now=j;
            ll sum=1;
            if(j+i*c>n)continue;
            rep(k,0,c){
                sum*=nck(n-now,i,mod);
                sum%=mod;
                now+=i;
            }
            ll g=c;
            for(;;){
                (dp[i][now]+=(dp[i-1][j]*sum)%mod*gya[g])%=mod;
                if(now+i>n)break;
                if(now+i>j+i*d)break;
                sum*=nck(n-now,i,mod);
                sum%=mod;
                now+=i;
                g++;
            }
        }
    }
    cout<<dp[b][n]<<endl;
}
