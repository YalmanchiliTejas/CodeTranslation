#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

//dp[l][r][bool] [l,r)を(bool)が先手のときの得点
ll dp[3002][3002][2]={0};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  std::vector<ll> a(n);
  rep(i,0,n)std::cin>>a[i];

  rep(i,0,n){
    dp[i][i+1][0]=a[i];
    dp[i][i+1][1]=-a[i];
  }

  rep(len,2,n+1){
    rep(i,0,n+1-len){
      dp[i][i+len][0]=std::max(a[i]+dp[i+1][i+len][1],a[i+len-1]+dp[i][i+len-1][1]);
      dp[i][i+len][1]=std::min(dp[i+1][i + len][0]-a[i],dp[i][i + len - 1][0]-a[i+len-1]);
    }
  }

  std::cout<<dp[0][n][0];

  return 0;
}