#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <tuple>
#include <functional>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <random>
#include <stack>

using namespace std;

#define endl '\n'

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using lld = long double;
using ull = unsigned long int;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int precision = 13;
  cout.precision(precision);
  cout.setf(ios_base::fixed);

  int n; cin >> n;
  vector<ll> a(n);
  for (auto& it : a) cin >> it;
  for (int i = 1; i < n; ++i) a[i] += a[i-1];

  vector<vector<ll>> dp(n, vector<ll>(n+1, 0));

  for (int i = 0; i < n; ++i) {
    dp[i][i] = a[i];
    if (i > 0) dp[i][i] -= a[i-1];
    for (int j = i-1; j >= 0; --j) {
      ll acc = a[i] - (j > 0 ? a[j-1] : 0);
      dp[i][j] = max(acc - dp[i-1][j], acc - dp[i][j+1]);
    }
  }

  cout << 2 * dp[n-1][0] -  a[n-1] << endl;

  return 0;
}
