#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) {
  v = vector<T>(n, x);
}
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n) {
  v = vector<T>(n); for (lli i=0; i<n; ++i) cin >> v[i];
}
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli n;
vector<lli> a;
vector<vector<lli>> dp;
int main() {
  cin >> n; read_n(a, n);
  init_n(dp, n, vector<lli>(n, 0));
  for (lli l=0; l<n; ++l) {
    dp[l][l] = (n&1)==0 ? -a[l] : a[l];
  }
  for (lli d=1; d<n; ++d) {
    for (lli l=0; l<n-d; ++l) {
      lli r = l+d;
      dp[l][r] = ((n-d)&1)==1 
	? max(dp[l+1][r] + a[l], dp[l][r-1] + a[r])
	: min(dp[l+1][r] - a[l], dp[l][r-1] - a[r]);
    }
  }
  cout << dp[0][n-1] << endl;
  return 0;
}
