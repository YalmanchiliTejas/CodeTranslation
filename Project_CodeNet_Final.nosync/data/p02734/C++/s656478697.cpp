#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
typedef pair<double,double> pdd;
typedef vector<vector<ll>> mat;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll mod5=1000000009;
ll inf=1LL<<60;
double pi=3.141592653589793238462643383279L;
double eps=1e-14;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
#define mrep(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
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
ll popcount(ll n){
    ll ret=0;
    ll u=n;
    while(u>0){
        ret+=u%2;
        u/=2;
        
    }
    return ret;
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
  for(int i=n-1;i>=1;i--){
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
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s;cin>>n>>s;
    int a[n];
    int sum[n+1];
    sum[0]=0;
    rep(i,0,n){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    ll dp[n+1][s+1];
    rep(i,0,n+1){
        rep(j,0,s+1)dp[i][j]=0;
    }
    dp[0][0]=1;
    rep(i,0,n){
        rep(j,0,s){
            (dp[i+1][j]+=dp[i][j])%=mod2;
            if(j+a[i]<=s){
                ll u=1;
                if(j==0)u=i+1;
                (dp[i+1][j+a[i]]+=dp[i][j]*u)%=mod2;
            }
        }
    }
    ll ans=0;
    rep(i,0,n+1){
        //rep(j,0,s+1)cout<<dp[i][j]<<" ";
        //cout<<endl;
    }
    rep(i,0,n+1){
        (ans+=dp[i][s]*(n-i+1))%=mod2;
    }
    cout<<ans<<endl;
}





