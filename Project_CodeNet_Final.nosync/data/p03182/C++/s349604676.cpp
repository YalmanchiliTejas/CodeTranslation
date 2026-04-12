#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 2147483647 / 2;
const long long int llINF = 9223372036854775807 / 2;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define SP(a) setprecision(a)
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))
#define UNIQUE(vec)                                                            \
  do {                                                                         \
    sort(ALL((vec)));                                                          \
    (vec).erase(std::unique(ALL((vec))), (vec).end());                         \
  } while (0)

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T, typename OP> class LazySegmentTree {
public:
  using MERGE = function<T(T, T)>;
  using APPLY = function<T(T, OP)>;
  using MERGE_OP = function<OP(OP, OP)>;

  MERGE merge_data_func;
  APPLY apply_lazy_func;
  MERGE_OP merge_lazy_func;
  T elem_ident;
  OP op_ident;
  std::vector<T> data;
  std::vector<OP> lazy;
  int n, height;

  LazySegmentTree(MERGE f, APPLY g, MERGE_OP h, T elem_ident, OP op_ident)
      : merge_data_func(f), apply_lazy_func(g), merge_lazy_func(h),
        elem_ident(elem_ident), op_ident(op_ident) {}

  void init(int n_temp) {
    n = 1;
    height = 0;
    while (n < n_temp) {
      n <<= 1;
      ++height;
    }
    data.assign(2 * n, elem_ident);
    lazy.assign(2 * n, op_ident);
  }

  void build(const std::vector<T> &v) {
    int n_temp = v.size();
    init(n_temp);
    std::copy(v.begin(), v.end(), data.begin() + n);
    for (int i = n - 1; i > 0; --i) {
      data[i] = merge_data_func(data[(i << 1) | 0], data[(i << 1) | 1]);
    }
  }

  inline T reflect_lazy(int k) {
    if (lazy[k] == op_ident) {
      return data[k];
    } else {
      T applied = apply_lazy_func(data[k], lazy[k]);
      return applied;
    }
  }

  inline void eval(int k) {
    if (lazy[k] == op_ident)
      return;
    lazy[(k << 1) | 0] = merge_lazy_func(lazy[(k << 1) | 0], lazy[k]);
    lazy[(k << 1) | 1] = merge_lazy_func(lazy[(k << 1) | 1], lazy[k]);
    data[k] = reflect_lazy(k);
    lazy[k] = op_ident;
  }

  inline void eval_down(int k) {
    for (int i = height; i > 0; --i) {
      eval(k >> i);
    }
  }

  inline void merge_up(int k) {
    while (k >>= 1) {
      data[k] = merge_data_func(reflect_lazy((k << 1) | 0),
                                reflect_lazy((k << 1) | 1));
    }
  }

  void update(int a, int b, OP x) {
    eval_down(a += n);
    eval_down(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        lazy[l] = merge_lazy_func(lazy[l], x);
        ++l;
      }
      if (r & 1) {
        --r;
        lazy[r] = merge_lazy_func(lazy[r], x);
      }
    }
    merge_up(a);
    merge_up(b);
  }

  void set_val(int a, T x) {
    eval_down(a += n);
    data[a] = x;
    lazy[a] = op_ident;
    merge_up(a);
  }

  T query(int a, int b) {
    eval_down(a += n);
    eval_down(b += n - 1);
    T vl = elem_ident, vr = elem_ident;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        vl = merge_data_func(vl, reflect_lazy(l++));
      }
      if (r & 1) {
        vr = merge_data_func(reflect_lazy(--r), vr);
      }
    }
    T merged = merge_data_func(vl, vr);
    return merged;
  }

  void desc() {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M;
  cin >> N >> M;
  vl L(M), R(M), A(M);

  vvl segment(N);

  auto f = [](ll a, ll b) { return max(a, b); };
  auto h = [](ll a, ll b) { return a + b; };

  REP(i, M) {
    cin >> L[i] >> R[i] >> A[i];
    L[i]--;
    R[i]--;
  }
  REP(i, M) segment[R[i]].push_back(i);

  LazySegmentTree<ll, ll> st(f, h, h, 0, 0);
  st.build(vl(N + 2, 0));
  st.desc();

  REP(i, N) {
    ll left = max(0LL, st.query(0, i));

    st.update(i, i + 1, left);
    AUTO(j, segment[i]) { st.update(L[j], R[j] + 1, A[j]); }
    st.desc();
  }
  cout << max(0LL, st.query(0, N + 1)) << endl;

  return 0;
}
