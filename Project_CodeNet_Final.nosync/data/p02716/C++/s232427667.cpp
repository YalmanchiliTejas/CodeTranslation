#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  bool isOdd = n%2 == 1;
  vector<ll> dp[3];
  rep(i,3) dp[i] = vector<ll>(n+1,0);
  rep(i,n){
    ll a;
    cin >> a;

    dp[0][i+1] = dp[0][i];
    if(i%2==0 && i <= n-2){
      dp[0][i+1] += a;
    }
    int ii = max(0,i-1);
    dp[1][i+1] = max(dp[1][i],dp[0][ii]);
    if(i%2==1){
      dp[1][i+1] += a;
    }
    if(isOdd){
      dp[2][i+1] = max(dp[2][i],dp[1][ii]);
      if(i%2==0){
        dp[2][i+1] += a;
      }
    }
  }
  ll ans = max(dp[0][n],dp[1][n]);
  if(isOdd) ans = max(ans,dp[2][n]);
  cout << ans << endl;
}
