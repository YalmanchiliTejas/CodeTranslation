#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const ll inf=1ll<<60;

ll dp[200010][3];

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n)rep(j,3) dp[i][j]=-inf;
  ll ans=-inf;
  if(n%2==0){
    dp[0][0]=a[0];
    dp[1][1]=a[1];
    rep(i,n)rep(j,2){
      if(i-2>=0) chmax(dp[i][j],a[i]+dp[i-2][j]);
      if(i-3>=0&&j-1>=0) chmax(dp[i][j],a[i]+dp[i-3][j-1]);
    }
    chmax(ans,dp[n-2][0]);
    chmax(ans,dp[n-1][1]);
  }
  else{
    dp[0][0]=a[0];
    dp[1][1]=a[1];
    dp[2][2]=a[2];
    rep(i,n)rep(j,3){
      if(i-2>=0) chmax(dp[i][j],a[i]+dp[i-2][j]);
      if(i-3>=0&&j-1>=0) chmax(dp[i][j],a[i]+dp[i-3][j-1]);
      if(i-4>=0&&j-2>=0) chmax(dp[i][j],a[i]+dp[i-4][j-2]);
    }
    chmax(ans,dp[n-3][0]);
    chmax(ans,dp[n-2][1]);
    chmax(ans,dp[n-1][2]);
  }
  cout << ans << endl;
}