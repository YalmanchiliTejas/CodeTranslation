#include <bits/stdc++.h>

#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif
#if __cplusplus <= 201402L
template <typename T>
T gcd(T a, T b) { return ((a % b == 0) ? b : gcd(b, a % b)); }
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
#endif
using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 1E9 + 7;

namespace Problem {
using namespace std;

struct RangeMax {
  using T = long long;
  T operator()(const T &a, const T &b) { return max(a, b); }
  static constexpr T id() { return T(-LINF); };
};

struct RangeAdd {
  using T = long long;
  T operator()(const T &a, const T &b) { return a + b; };
  static constexpr T id() { return T(0); };
};

struct Max_Add {
  using V = RangeMax;
  using A = RangeAdd;
  V::T operator()(const V::T &a, const A::T &b, const int &h) { return a + b; };
};
template <typename M>
struct LazySegmentTree {
  using Val = typename M::V::T;
  using Del = typename M::A::T;
  typename M::V calc;
  typename M::A composite;
  M act;
  vector<Val> val;
  vector<Del> delay;

  int n, height;
  explicit LazySegmentTree(int size) : n(1), height(0) {
    while (n < size) {
      n <<= 1;
      ++height;
    }
    val = vector<Val>(n << 1, calc.id());
    delay = vector<Del>(n << 1, composite.id());
  }
  explicit LazySegmentTree(const vector<Val> &v) : n(1), height(0) {
    while (n < v.size()) {
      n <<= 1;
      ++height;
    }
    val = vector<Val>(n << 1, calc.id());
    delay = vector<Del>(n << 1, composite.id());
    copy(v.begin(), v.end(), val.begin() + n);
    for (int i = n - 1; i > 0; --i) {
      val[i] = calc(val[i * 2], val[i * 2 + 1]);
    }
  }
  void propagate(int k, int h) {
    val[k] = act(val[k], delay[k], h);
    if (h > 0) {
      delay[2 * k] = composite(delay[2 * k], delay[k]);
      delay[2 * k + 1] = composite(delay[2 * k + 1], delay[k]);
    }
    delay[k] = composite.id();
  }
  inline void update(int l, int r, Del v) { update(l, r, v, 1, 0, n, height); }
  void update(int l, int r, Del v, int k, int a, int b, int h) {
    if (l <= a && b <= r) {
      delay[k] = composite(delay[k], v);
      propagate(k, h);
      return;
    }
    propagate(k, h);
    if (b <= l || r <= a) {
      return;
    }  //
    update(l, r, v, 2 * k, a, (a + b) / 2, h - 1);
    update(l, r, v, 2 * k + 1, (a + b) / 2, b, h - 1);
    val[k] = calc(val[2 * k], val[2 * k + 1]);
  }
  inline Val query(int l, int r) { return query(l, r, 1, 0, n, height); }
  Val query(int l, int r, int k, int a, int b, int h) {
    if (b <= l || r <= a) {
      return calc.id();
    }  //
    propagate(k, h);
    if (l <= a && b <= r) {
      return val[k];
    }
    Val vall = query(l, r, 2 * k, a, (a + b) / 2, h - 1);
    Val valr = query(l, r, 2 * k + 1, (a + b) / 2, b, h - 1);
    return calc(vall, valr);
  }
};

class Solver2 {
 public:
  int n, m;
  vector<vector<pair<int, LL>>> r, l;
  LazySegmentTree<Max_Add> seg;
  vector<LL> dp;
  Solver2(LL n, LL m) : n(n), m(m), r(n + 1), l(n + 1), seg(vector<LL>(n + 1, 0)), dp(n + 1){};

  void solve() {
    for (int i = 0; i < m; ++i) {
      int L, R;
      LL A;
      cin >> L >> R >> A;
      r[L].emplace_back(R, A);
      l[R].emplace_back(L, A);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < r[i].size(); ++j) {
        seg.update(0, i, r[i][j].second);
      }
      for (int k = 0; k < n; ++k) {
        DBG(k, seg.query(k, k + 1))
      }
      dp[i] = seg.query(0, i);
      seg.update(i, i + 1, dp[i]);
      for (int j = 0; j < l[i].size(); ++j) {
        seg.update(0, l[i][j].first, -l[i][j].second);
      }
    }
    for (int k = 0; k < n; ++k) {
      DBG(k, seg.query(k, k + 1))
    }
    DBG(dp)
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }
};
}  // namespace Problem

signed main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(12);
  long long n = 0, m;
  std::cin >> n >> m;

  Problem::Solver2 sol(n, m);
  sol.solve();
  return 0;
}
