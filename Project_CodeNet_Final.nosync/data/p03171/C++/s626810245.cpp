#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <list>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
constexpr int maxn = 3000;
constexpr ll inf = (ll) 1000000000000000;
ll dp[maxn + 1][maxn + 1][2];

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int& e : v) cin >> e;

  for (int i = 0; i <= n; i++) dp[i][i][0] = dp[i][i][1] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j + i <= n; j++) {
      int b = j, e = j + i;
      for (int k = 0; k < 2; k++) {
        ll& ans = dp[b][e][k];
        ans = (k == 0) ? -inf : inf;

        if (k == 0) {
          ans = max(ans, v[b] + dp[b + 1][e][!k]);
          ans = max(ans, v[e - 1] + dp[b][e - 1][!k]);
        } else {
          ans = min(ans, dp[b + 1][e][!k] - v[b]);
          ans = min(ans, dp[b][e - 1][!k] - v[e - 1]);
        }
      }
    }
  }
  cout << dp[0][n][0] << endl;
  return 0;
}
