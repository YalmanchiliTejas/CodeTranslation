#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j;
  ll n;
  cin>>n;
  VI a(n);
  for(i=0;i<n;i++) cin>>a[i];
  VVI dp(n+1,VI(8,-INF));
  dp[0][7]=a[0];
  dp[0][1]=0;
  for(i=1;i<n;i++){
    for(j=5;j<8;j++) chmax(dp[i][j],dp[i-1][j-5]+a[i]);
    for(j=0;j<3;j++) chmax(dp[i][j],dp[i-1][j+5]);
    for(j=0;j<3;j++) chmax(dp[i][j],dp[i-1][j+1]);
  }
  if(n%2==0) cout<<max(dp[n-1][2],dp[n-1][6])<<endl;
  else cout<<max(dp[n-1][1],dp[n-1][5])<<endl;

  

}