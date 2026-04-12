#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<tll,vector<tll>,greater<tll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n;
  cin>>n;
  vll a(n);
  rep(i,n) cin>>a[i];
  if(n%2==0){
    vvll dp(n+1,vll(2,-INF));
    dp[1][0]=a[0];
    dp[2][1]=a[1];
    rep(i,n)rep(j,2){
      if(dp[i][j]==-INF) continue;
      if(i+2<n+1){
        chmax(dp[i+2][j],dp[i][j]+a[i+1]);
      }
      if(j==0&&i+3<n+1){
        chmax(dp[i+3][j+1],dp[i][j]+a[i+2]);
      }
    }
    ll ans=max(dp[n-1][0],dp[n][1]);
    COUT(ans);
  }
  else{
    vvll dp(n+1,vll(3,-INF));
    dp[1][0]=a[0];
    dp[2][1]=a[1];
    dp[3][2]=a[2];
    rep(i,n)rep(j,3){
      if(dp[i][j]==-INF) continue;
      if(i+2<n+1){
        chmax(dp[i+2][j],dp[i][j]+a[i+1]);
      }
      if(j==0){
        if(i+3<n+1){
          chmax(dp[i+3][j+1],dp[i][j]+a[i+2]);
        }
        if(i+4<n+1){
          chmax(dp[i+4][j+2],dp[i][j]+a[i+3]);
        }
      }
      if(j==1){
        if(i+3<n+1){
          chmax(dp[i+3][j+1],dp[i][j]+a[i+2]);
        }
      }
    }
    ll ans=max(max(dp[n-2][0],dp[n-1][1]),dp[n][2]);
    COUT(ans);
  }
}
