//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll n;cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  reverse(a.begin(),a.end());
  ll dp[114514];
  rep(i,n+1)dp[i]=INF;
  rep(i,n){
    *upper_bound(dp,dp+n,a[i])=a[i];
  }
  ll ans=lower_bound(dp,dp+n,INF)-dp;
  cout<<ans<<endl;
}
