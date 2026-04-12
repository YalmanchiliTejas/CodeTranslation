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
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

struct E { lli i, j, c; };

lli n;
vector<lli> x, y;
vector<E> e;
vector<lli> uf;

lli root(lli i) {
  if (uf[i] < 0) return i;
  return uf[i] = root(uf[i]);
}

bool same(lli i, lli j) {
  return root(i) == root(j);
}

void unite(lli i, lli j) {
  if (!same(i, j)) uf[root(i)] = root(j);
}

int main() {
  cin >> n;
  init_n(x, n); init_n(y, n);
  for (lli i=0; i<n; ++i) cin >> x[i] >> y[i];

  vector<lli> ix(n); iota(begin(ix), end(ix), 0);
  sort(begin(ix), end(ix), [&](lli i, lli j) { return x[i] < x[j]; });
  for (lli i=0; i<n-1; ++i) 
    e.push_back({ix[i], ix[i+1], abs(x[ix[i+1]] - x[ix[i]])});
  vector<lli> iy(n); iota(begin(iy), end(iy), 0);
  sort(begin(iy), end(iy), [&](lli i, lli j) { return y[i] < y[j]; });
  for (lli i=0; i<n-1; ++i) 
    e.push_back({iy[i], iy[i+1], abs(y[iy[i+1]] - y[iy[i]])});

  sort(begin(e), end(e), [](E& e, E& f) { return e.c < f.c; });

  init_n(uf, n, -1);
  lli ans = 0;
  for (E& f : e) {
    // cout << f.i << ',' << f.j << ' ' << f.c << endl;
    if (!same(f.i, f.j)) {
      unite(f.i, f.j);
      ans += f.c;
    }
  }

  cout << ans << endl;
  return 0;
}

