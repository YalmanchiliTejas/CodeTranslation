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
ll mod = 1e9 + 7;

int main() {
  string k;
  int d;
  cin >> k >> d;

  int n = k.size();

  ll dp[n + 1][d][2];
  for (int i = 0; i < d; i++) dp[n][i][0] = dp[n][i][1] = 0;
  dp[n][0][0] = dp[n][0][1] = 1;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < d; j++) {
      for (int limit : {0, 1}) {
        ll& ans = dp[i][j][limit];
        ans = 0;

        int ub = limit ? (k[i] - '0') : 9;
        for (int k = 0; k <= ub; k++) {
          ans += dp[i + 1][(j + k) % d][limit && (k == ub)];
          ans %= mod;
        }
      }
    }
  }
  cout << (dp[0][0][1] + mod - 1) % mod << endl;

  return 0;
}
