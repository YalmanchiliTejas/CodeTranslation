#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <map>
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
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli n, k, a[3000];
lli memo[3001][3001];

lli dfs(lli t, lli l, lli r) {
  if (memo[l][r] != 1e18) return memo[l][r];
  lli yl = dfs(-t, l+1, r);
  lli yr = dfs(-t, l, r-1);
  lli res;
  if (t == 1) res = max(yl + a[l], yr + a[r]);
  else res = min(yl - a[l], yr - a[r]);
  return memo[l][r] = res;
}

int main() {
  cin >> n;
  read_n(a, n);
  for (lli i=0; i<n; ++i) fill(&memo[i][i], &memo[i][n+1], 1e18);
  cout << dfs(1, 0, n-1) << '\n';
  return 0;
}

