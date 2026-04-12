#include <iostream>
#include <functional>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
 
const ll INF = 1e18;
 
ll dp[200005][4];

int main() {
  int n;
  cin>>n;
  ll a[n];
  rep(i,n) cin >> a[i];
  int k = 1+n%2;
  rep(i,n+1)rep(j,k+1) dp[i][j] = -INF;
  dp[0][0] = 0;
  rep(i,n) {
    rep(j,k+1) {
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        if ((i+j)%2 == 0){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+a[i]);
        }else{
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
  }
  ll ans = dp[n][k];
  cout << ans << endl;
  return 0;
}