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

int main() {
  
  int n, s; cin >> n >> s;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<lint>> dp(n + 1, vector<lint> (s + 1, 0));

  for (int i = 0; i <= n; i++) dp[i][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;

      if (j + a[i] <= s) {
        dp[i + 1][j + a[i]] += dp[i][j];
        dp[i + 1][j + a[i]] %= MOD;
      }
    }
  }

  lint ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[i][s];
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
