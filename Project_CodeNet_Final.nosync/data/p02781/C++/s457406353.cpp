#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

ll dp[105][4] ;
ll ep[105][4] ;
int main(){
  string s ; cin>>s ;
  ll k ; cin>>k ;
  ll x= s.size() ;
  rep(i,105){
      rep(j,4){
          dp[i][j]=0 ;
          ep[i][j]=0 ;
      }
  }
  ep[0][0]= 1 ; 
  rep2(i,1,x){
     ll now = s[i-1]-'0' ; 
      rep(j,4){
          dp[i][j] += dp[i-1][j] ;
          if(j>0) dp[i][j]+= dp[i-1][j-1]*9 ;
          dp[i][j] += ep[i-1][j]*min(1ll,now) ;
          if(j>0) dp[i][j]+=ep[i-1][j-1]*max(0ll,now-1) ;
          if(now!=0&&j>0) ep[i][j]=ep[i-1][j-1] ;
          if(now==0) ep[i][j]=ep[i-1][j] ;
      }
  }
  ll ans = dp[x][k] + ep[x][k] ;
  cout<<ans<<endl ;
   return 0 ; 
}

