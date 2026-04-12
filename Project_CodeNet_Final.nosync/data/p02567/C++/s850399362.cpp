#include <bits/stdc++.h>

#include <atcoder/all>

#define DEF_SEGTREE(name, T, op, e)                     \
  namespace __##name {                                  \
    inline T _op(T a, T b) { return (op); }             \
    inline T _e() { return (e); }                       \
    using type = typename atcoder::segtree<T, _op, _e>; \
  }                                                     \
  using name = __##name::type;

#define DEF_LAZYSEGTREE(name, T, op, e, F, mapping, composition)                             \
  namespace name {                                                                           \
  struct _T {                                                                                \
    T value;                                                                                 \
    int left, right, size;                                                                   \
    inline _T(const T& value, int left, int right, int size)                                 \
        : value(value), left(left), right(right), size(size) {}                              \
    inline _T(const T& value, int left = 0, int right = 1)                                   \
        : _T(value, left, right, right - left) {}                                            \
    inline _T() : _T((e), -1, -1, 0) {}                                                      \
  };                                                                                         \
  inline _T _op(_T _a, _T _b) {                                                              \
    const auto &a = _a.value, &b = _b.value;                                                 \
    int newLeft = (_a.size > 0 ? _a : _b).left;                                              \
    int newRight = (_b.size > 0 ? _b : _a).right;                                            \
    int newSize = _a.size + _b.size;                                                         \
    return _T((op), newLeft, newRight, newSize);                                             \
  }                                                                                          \
  inline _T _e() { return _T(); }                                                            \
  struct _F {                                                                                \
    F value;                                                                                 \
    bool enabled;                                                                            \
    inline _F(const F& value, bool enabled = true)                                           \
        : value(value), enabled(enabled) {}                                                  \
    inline _F() : _F(F(), false) {}                                                          \
  };                                                                                         \
  inline _T _mapping(_F _f, _T _a) {                                                         \
    if (!_f.enabled) return _a;                                                              \
    const auto& f = _f.value;                                                                \
    const auto& a = _a.value;                                                                \
    int l = _a.left, r = _a.right, s = _a.size;                                              \
    return _T((mapping), _a.left, _a.right, _a.size);                                        \
  }                                                                                          \
  inline _F _composition(_F _f, _F _g) {                                                     \
    if (!_f.enabled) return _g;                                                              \
    if (!_g.enabled) return _f;                                                              \
    const auto &f = _f.value, &g = _g.value;                                                 \
    return _F((composition), true);                                                          \
  }                                                                                          \
  inline _F _id() { return _F(); }                                                           \
  using type = typename atcoder::lazy_segtree<_T, _op, _e, _F, _mapping, _composition, _id>; \
  inline type generate(int n) {                                                              \
    std::vector<_T> _v(n);                                                                   \
    for (int i = 0; i < n; ++i) _v[i] = _T(e, i, i + 1, 1);                                  \
    return type(std::move(_v));                                                              \
  }                                                                                          \
  inline type generate(const std::vector<T>& v) {                                            \
    const int n = v.size();                                                                  \
    std::vector<_T> _v(n);                                                                   \
    for (int i = 0; i < n; ++i) _v[i] = _T(v[i], i, i + 1, 1);                               \
    return type(std::move(_v));                                                              \
  }                                                                                          \
  }

// #LIB#

using namespace std;
using namespace atcoder;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#ifdef ONLINE_JUDGE
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');
#endif

DEF_SEGTREE(seg, ll, max(a, b), LLONG_MIN)

int main() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  seg st(a);
  rep(i, q) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll x, v;
      cin >> x >> v;
      --x;
      st.set(x, v);
    } else if (t == 2) {
      ll l, r;
      cin >> l >> r;
      --l;
      cout << st.prod(l, r) << endl;
    } else if (t == 3) {
      ll x, v;
      cin >> x >> v;
      --x;
      cout << st.max_right(x, [&](ll a) { return a < v; }) + 1 << endl;
    }
  }
}
