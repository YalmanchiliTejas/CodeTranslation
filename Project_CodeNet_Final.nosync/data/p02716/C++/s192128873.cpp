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
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

lint solve(vector<lint> a, int dep) {
  int n = a.size();
  int m = n / 2;
  vector<vector<lint>> dp(m + 1, vector<lint> (dep, -INF));
  dp[0][0] = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < dep; j++) {
      if (dp[i][j] == -INF) continue;
      // cerr << "curState: " << i << " " << j << endl;
      for (int nj = j; nj < dep; nj++) {
        int takeId = i * 2 + nj;
        // cerr << "nextState: " << i + 1 << " " << nj << " takeId: " << takeId << endl;
        if (takeId < n) {
          dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + a[takeId]);
        }
      }

      // cerr << endl;
    }
  }

  lint ans = -INF;
  for (int j = 0; j < dep; j++)
    ans = max(ans, dp[m][j]);
  
  return ans;
}


int main() {
  
  int n; cin >> n;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int dep;
  if (n % 2 == 0) {
    dep = 2;
  } else {
    dep = 3;
  }
  
  lint ans = solve(a, dep);
  cout << ans << endl;
  return 0;
}
