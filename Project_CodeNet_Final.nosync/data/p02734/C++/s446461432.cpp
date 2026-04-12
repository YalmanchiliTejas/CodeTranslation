#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 998244353LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

lint dp[3030][3030][3];
int a[3030];

int main() {
  
  int n, k; cin >> n >> k;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
      (dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
      (dp[i + 1][j][2] += dp[i][j][2] + dp[i][j][1] + dp[i][j][0]) %= MOD;

      if (j + a[i] <= k) {
        (dp[i + 1][j + a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= MOD;
        (dp[i + 1][j + a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= MOD;
      }
    }
  }

  cout << dp[n][k][2] << endl;
  
  return 0;
}
