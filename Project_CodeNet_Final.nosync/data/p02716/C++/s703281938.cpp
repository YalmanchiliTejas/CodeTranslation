#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

vll as;

void solvee(ll n){
  vll dp(n+1, -1);
  dp[0] = 0;
  rep(i, n){
    if(i & 1){
      ll add = dp[i-1];
      if(i - 2 >= 0) chmax(add, dp[i-2]);
      dp[i+1] = add+ as[i];
    } else {
      dp[i+1] = as[i];
      if(i - 1 >= 0) dp[i+1] += dp[i-1];
    }
  }
  cout << max(dp[n], dp[n-1]) << endl;
}

void solveo(ll n){
  vvll dp(n, vll(3, -INF));

  dp[0][0] = as[0];
  dp[1][1] = as[1];
  dp[2][0] = as[0] + as[2];
  dp[2][2] = as[2];

  repLRE(i, 3, n-1){
    rep(j, 3){
      if(i - 2 >= 0 && dp[i-2][j] != -INF) chmax(dp[i][j], dp[i-2][j] + as[i]);
      if(j == 2){
        if(i - 4 >= 0 && dp[i-4][j-2] != -INF) chmax(dp[i][j], dp[i-4][j-2] + as[i]);
      }
      if(j >= 1){
        if(i - 3 >= 0 && dp[i-3][j-1] != -INF) chmax(dp[i][j], dp[i-3][j-1] + as[i]);
      }
    }
  }

  ll ans = dp[n-1][2];
  chmax(ans, dp[n-2][1]);
  chmax(ans, dp[n-3][0]);
  cout << ans << endl;
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;

  as.resize(n);
  rep(i,n) cin >> as[i];
  if(n & 1){
    solveo(n);
  } else {
    solvee(n);
  }

  return 0;
}
