/**
 *    author:  tourist
 *    created: 26.11.2019 09:10:09       
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> e(m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    e[i] = make_tuple(z, x, y);
  }
  sort(e.begin(), e.end());
  long long ans = 0;
  vector<int> fi(n);
  iota(fi.begin(), fi.end(), 0);
  vector<int> ne(n, -1);
  vector<int> nc(n, -1);
  dsu d(n);
  for (auto& ee : e) {
    int x = get<1>(ee);
    int y = get<2>(ee);
    int z = get<0>(ee);
    x = d.get(x);
    y = d.get(y);
    if (x != y) {
      d.p[x] = y;
      ne[x] = fi[y];
      nc[x] = z;
      fi[y] = fi[x];
      ans += z;
    }
  }
  int start = fi[d.get(0)];
  vector<int> order(n);
  vector<int> val(n - 1);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    if (i < n - 1) {
      val[i] = nc[start];
    }
    order[i] = start;
    pos[start] = i;
    start = ne[start];
  }
  SparseTable<int> st(val, [&](int i, int j) { return max(i, j); });
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    x = pos[x];
    y = pos[y];
    if (x > y) {
      swap(x, y);
    }
    cout << ans - st.get(x, y - 1) << '\n';
  }
  return 0;
}
