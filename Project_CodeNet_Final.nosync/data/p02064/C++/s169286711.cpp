#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  int n, s, t; cin >> n >> s >> t, --s, --t;
  auto qry = [&](int u, int v) -> int {
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int res; cin >> res;
    assert(res != -1);
    return res;
  };
  int d = qry(s, t);
  V<> ds(n), dt(n);
  ds[t] = dt[s] = d;
  for (int v = 0; v < n; ++v) if (v != s and v != t) {
    ds[v] = qry(s, v);
    dt[v] = qry(t, v);
  }
  V<> vs(n);
  iota(begin(vs), end(vs), 0);
  sort(begin(vs), end(vs), [&](int u, int v) { return ds[u] < ds[v]; });
  V<> res;
  int p = s;
  for (int v : vs) if (ds[v] + dt[v] == d) {
    if (ds[p] + qry(p, v) + dt[v] > d) continue;
    res.push_back(v);
  }
  cout << '!';
  for (int e : res) cout << ' ' << e + 1;
  cout << endl;
}
