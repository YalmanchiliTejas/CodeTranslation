#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define repi(n) for (int i = 0; i < (n); i++)
#define repj(n) for (int j = 0; j < (n); j++)
#define repk(n) for (int k = 0; k < (n); k++)
#define repl(n) for (int l = 0; l < (n); l++)
#define rep(i, n) for (int i = 0; (i) < (n); i++)
#define repr(i, a, b) for (auto i = (a); i < (b); i++)
#define repv(itr) for (auto&& v : (itr))
#define repv2(itr) for (auto&& v2 : (itr))
#define repv3(itr) for (auto&& v3 : (itr))
#define updatemax(t, v) (t = max((t), (v)))
#define updatemin(t, v) (t = min((t), (v)))
const int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
const double PI = atan(1.0) * 4;
template <typename T>
T minptr(T begin, T end) {
  T re = begin;
  for (T i = begin + 1; i != end; i++) {
    if (*i < *re) re = i;
  }
  return re;
}
template <typename T>
T maxptr(T begin, T end) {
  T re = begin;
  for (T i = begin + 1; i != end; i++) {
    if (*i > *re) re = i;
  }
  return re;
}
int __vmax(int x) {
  return INT_MAX;
}
double __vmax(double x) {
  return 1e+300;
}
ll __vmax(ll x) {
  return LLONG_MAX;
}
int __vmin(int x) {
  return INT_MIN;
}
double __vmin(double x) {
  return -1e+300;
}
ll __vmin(ll x) {
  return LLONG_MIN;
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : b == 1 ? 1 : gcd(b, a % b);
}
template <typename T>
T bsearch(T begin, T end, function<bool(T)> f, T targetwidth) {
  if (f(begin)) return begin;
  if (!f(end)) return end;
  while (abs(end - begin) > targetwidth) {
    T m = (begin + end) / 2;
    if (f(m)) {
      end = m;
    } else {
      begin = m;
    }
  }
  return end;
}
ll bsearchi(ll begin, ll end, function<bool(ll)> f) {
  return bsearch<ll>(begin, end, f, 1);
}
double bsearchd(double begin, double end, function<bool(double)> f) {
  return bsearch<double>(begin, end, f, max(abs(begin), abs(end)) * 1e-14);
}
ll modpow(ll a, ll b, ll m) {
  ll re = 1, k = 1;
  while (k <= b) {
    if (b & k) {
      re *= a;
      re %= m;
    }
    k = k << 1;
    a *= a;
    a %= m;
  }
  return re;
}
ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
ll modbinomial(ll n, ll k, ll m) {
  k = min(k, n - k);
  if (k < 0) return 0;
  ll re = 1;
  for (ll i = 0; i < k; i++) {
    re *= n - i;
    re %= m;
    re *= modinv(i + 1, m);
    re %= m;
  }
  return re;
}
template <typename T>
vector<T> lis(T begin, T end, bool allowequal = false, bool lds = false) {
  using V = typename iterator_traits<T>::value_type;
  int n = end - begin;
  vector<V> a(n, lds ? __vmin(*begin) : __vmax(*begin));
  vector<int> id(n);
  if (lds && allowequal) {
    for (int i = 0; i < n; i++) {
      id[i] = n - 1 -
              (lower_bound(a.rbegin(), a.rend(), begin[i]) - 1 - a.rbegin());
      a[id[i]] = begin[i];
    }
  } else if (lds) {
    for (int i = 0; i < n; i++) {
      id[i] = n - 1 -
              (upper_bound(a.rbegin(), a.rend(), begin[i]) - 1 - a.rbegin());
      a[id[i]] = begin[i];
    }
  } else if (allowequal) {
    for (int i = 0; i < n; i++) {
      id[i] = upper_bound(a.begin(), a.end(), begin[i]) - a.begin();
      a[id[i]] = begin[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      id[i] = lower_bound(a.begin(), a.end(), begin[i]) - a.begin();
      a[id[i]] = begin[i];
    }
  }
  int m = *maxptr(id.begin(), id.end());
  vector<T> re(m + 1);
  for (int i = n - 1; i >= 0; i--) {
    if (id[i] == m) re[m--] = begin + i;
  }
  return re;
}
class uftree {
 private:
  int n, groups;
  vector<int> parent, size;

 public:
  uftree(int _n) {
    groups = n = _n;
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int group(int x) {
    if (parent[x] == x) return x;
    return parent[x] = group(parent[x]);
  }
  bool inSameGroup(int x, int y) { return group(x) == group(y); }
  int groupSizeOf(int x) { return size[group(x)]; }
  void merge(int x, int y) {
    int gx = group(x), gy = group(y);
    if (gx != gy) {
      parent[gx] = gy;
      size[gy] += size[gx];
      size[gx] = 0;
      groups--;
    }
  }
  int countGroups() { return groups; }
};
template <typename T>
class segtree {
 private:
  int n;
  function<T(T, T)> f;
  T e;
  vector<T> data, lazy;
  void _updateP(int i) {
    data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
    if (i) _updateP((i - 1) / 2);
  }
  T _calc(int begin, int end, int node, int nodeBegin, int nodeEnd) {
    if (end <= nodeBegin || nodeEnd <= begin) {
      return e;
    } else if (begin <= nodeBegin && nodeEnd <= end) {
      return data[node];
    } else {
      int m = (nodeBegin + nodeEnd) / 2;
      T left = _calc(begin, end, node * 2 + 1, nodeBegin, m);
      T right = _calc(begin, end, node * 2 + 2, m, nodeEnd);
      return f(left, right);
    }
  }

 public:
  segtree(int n_, function<T(T, T)> f_, T e_, T fill) {
    n = pow(2, ceil(log2(n_)));
    f = f_;
    e = e_;
    data.resize(n * 2 - 1);
    for (int i = 0; i < n * 2 - 1; i++) data[i] = fill;
  }
  segtree(int n_, function<T(T, T)> f_, T e_) : segtree(n_, f_, e_, e_) {}
  T value(int i) { return data[n - 1 + i]; }
  void update(int i, T value) {
    data[n - 1 + i] = value;
    if (n) _updateP((n - 2 + i) / 2);
  }
  T calc(int begin, int end) { return _calc(begin, end, 0, 0, n); }
  static T max(T a, T b) { return std::max(a, b); }
  static T min(T a, T b) { return std::min(a, b); }
  static T sum(T a, T b) { return a + b; }
};

// E
// bool white[1000][10];
// main() {
//   int h, w, k;
//   cin >> h >> w >> k;
//   repj(h) repi(w) {
//     char c;
//     cin >> c;
//     white[i][j] = (c == '1');
//   }
// }

// F
int a[3000];
ll waru = 998244353;
ll dp[3001][3002];
main() {
  int n, s;
  cin >> n >> s;
  repi(n) cin >> a[i];
  repi(n + 1) dp[i][0] = 1 + i;
  ll answer = 0;
  repi(n) repj(s) {
    if (j > 0) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= waru;
    }
    int jtarget = min(j + a[i], s + 1);
    dp[i + 1][jtarget] += dp[i][j];
    dp[i + 1][jtarget] %= waru;
    if (jtarget == s) {
      answer += (dp[i + 1][jtarget] * (n - i)) % waru;
      answer %= waru;
      dp[i + 1][jtarget] = 0;
    }
  }
  cout << answer << endl;
}
