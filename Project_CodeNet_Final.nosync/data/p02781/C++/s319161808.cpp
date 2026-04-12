#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1LL<<60;
long double pi=3.14159265358979323846L;
double eps=1e-12;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
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
int sum[2001][2001];
ll f(int x1,int y1,int x2,int y2){
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int k;cin>>k;
    int n=s.size();
    ll dp[n+1][5][2];
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    rep(i,0,n){
        rep(j,0,4){
            if(s[i]-'0'==0){
                dp[i+1][j][0]+=dp[i][j][0];
                dp[i+1][j][1]+=dp[i][j][1];
                dp[i+1][j+1][1]+=dp[i][j][1]*9;
            }
            else{
                int u=s[i]-'0';
                dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1];
                dp[i+1][j+1][0]+=dp[i][j][0];
                dp[i+1][j+1][1]+=dp[i][j][0]*(u-1)+dp[i][j][1]*9;
            }
        }
    }
    cout<<dp[n][k][0]+dp[n][k][1]<<endl;
}
