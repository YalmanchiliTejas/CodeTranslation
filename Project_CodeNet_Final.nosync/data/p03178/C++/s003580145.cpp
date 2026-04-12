#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
#else
#define debug(x) ;
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

int dp[SIZE][100][3]; //{桁, mod, {0: 等, 1: 多, 2: 少}}

int main(){
  string k;
  int d;

  cin >> k >> d;

  dp[0][0][0] = 1;

  ll ans = 0;

  for(int i=0;i<k.size();i++){
    int p = k[i] - '0';
    debug(p);

    for(int j=0;j<d;j++){
      for(int l=(i==0);l<=9;l++){
        if(l < p) {
          dp[i+1][(j+l)%d][1] += dp[i][j][1];
          dp[i+1][(j+l)%d][2] += dp[i][j][0] + dp[i][j][2];
        }
        if(l == p) {
          dp[i+1][(j+l)%d][0] += dp[i][j][0];
          dp[i+1][(j+l)%d][1] += dp[i][j][1];
          dp[i+1][(j+l)%d][2] += dp[i][j][2];
        }
        if(l > p) {
          dp[i+1][(j+l)%d][1] += dp[i][j][0] + dp[i][j][1];
          dp[i+1][(j+l)%d][2] += dp[i][j][2];
        }

        dp[i+1][(j+l)%d][0] %= mod;
        dp[i+1][(j+l)%d][1] %= mod;
        dp[i+1][(j+l)%d][2] %= mod;
      }
    }
  }

  for(int i=1;i<=k.size();i++){
    ans += dp[i][0][0] + dp[i][0][2];
    if(i < k.size()) ans += dp[i][0][1];
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
