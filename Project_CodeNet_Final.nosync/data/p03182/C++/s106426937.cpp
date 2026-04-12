#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/*BigInteger
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/rational.hpp>
namespace xxx = boost::multiprecision;
using Bint = xxx::cpp_int;
using Real = xxx::number<xxx::cpp_dec_float<1024>>;
*/

#define int long long
#define pb(x) push_back(x)
#define m0(x) memset((x), 0LL, sizeof(x))
#define mm(x) memset((x), -1LL, sizeof(x))

//container
#define ALL(x) (x).begin(), (x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
#define PERM(c) \
  sort(ALL(c)); \
  for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))

// debug
#define GET_VAR_NAME(variable) #variable
#define test(x) cout << GET_VAR_NAME(x) << " = " << x << endl;

// bit_macro
#define Bit(n) (1LL << (n))
#define Bitset(a, b) (a) |= (1LL << (b))
#define Bitunset(a, b) (a) &= ~(1LL << (b))
#define Bitcheck(a, b) ((((a) >> (b)) & 1LL) == 1LL)
#define Bitcount(a) __builtin_popcountll((a))

//typedef
typedef long long lint;
typedef unsigned long long ull;
typedef complex<long double> Complex;
typedef pair<int, int> P;
typedef tuple<int, int, int> TP;
typedef vector<int> vec;
typedef vector<vec> mat;

//constant
constexpr int INF = (int)1e18;
constexpr int MOD = (int)1e9 + 7;
constexpr double PI = (double)acos(-1);
constexpr double EPS = (double)1e-10;
constexpr int dx[] = {-1, 0, 0, 1, 0, -1, -1, 1, 1};
constexpr int dy[] = {0, -1, 1, 0, 0, 1, -1, 1, -1};

//
template <typename T>
void chmax(T &a, T b) { a = max(a, b); }
template <typename T>
void chmin(T &a, T b) { a = min(a, b); }
//
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

//
struct Accelerate_Cin {
  Accelerate_Cin() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
  };
};

template <typename T, typename E>
struct LazySegmentTree {
  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  using P = function<E(E, int)>;
  int n;
  F f;
  G g;
  H h;
  P p;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;

  LazySegmentTree() {}

  LazySegmentTree(int n_, F f, G g, H h, T d1, E d0,
                  vector<T> v = vector<T>(), P p = [](E a, int b) { return a; }) : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
    init(n_);
    if (n_ == (int)v.size()) build(n_, v);
  }

  void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    dat.clear();
    dat.resize(2 * n - 1, d1);
    laz.clear();
    laz.resize(2 * n - 1, d0);
  }

  void build(int n_, vector<T> v) {
    for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
  }

  inline void eval(int len, int k) {
    if (laz[k] == d0) return;
    if (k * 2 + 1 < n * 2 - 1) {
      laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
      laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
    }
    dat[k] = g(dat[k], p(laz[k], len));
    laz[k] = d0;
  }

  T update(int a, int b, E x, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return dat[k];
    if (a <= l && r <= b) {
      laz[k] = h(laz[k], x);
      return g(dat[k], p(laz[k], r - l));
    }
    return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                      update(a, b, x, k * 2 + 2, (l + r) / 2, r));
  }

  T update(int a, int b, E x) {
    return update(a, b, x, 0, 0, n);
  }

  T query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return d1;
    if (a <= l && r <= b) return dat[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return f(vl, vr);
  }

  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

vector<P> G[202020];

signed main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int l, r, a;
    cin >> l >> r >> a;
    l--, r--;
    G[r].push_back({l, a});
  }

  auto f = [&](int a, int b) { return max(a, b); };
  auto g = [&](int a, int b) { return (a + b); };
  auto h = [&](int a, int b) { return (a + b); };

  LazySegmentTree<int, int> dp = {N, f, g, h, 0, 0, vector<int>(N, 0)};

  for (int i = 0; i < N; i++) {
    int now = 0;
    if (i > 0) now = max(now, dp.query(0, i));
    dp.update(i, i + 1, now);
    for (auto x : G[i]) {
      int l = x.first, add = x.second;
      dp.update(l, i + 1, add);
    }
  }

  cout << max(0LL, dp.query(0, N)) << endl;
  return 0;
}
