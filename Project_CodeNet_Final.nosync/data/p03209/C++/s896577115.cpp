#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define repi(n) for (int i = 0; i < (n); i++)
#define repj(n) for (int j = 0; j < (n); j++)
#define repk(n) for (int k = 0; k < (n); k++)
#define rep(i, n) for (int i = 0; (i) < (n); i++)
#define repr(i, a, b) for (auto i = (a); i < (b); i++)
#define repv(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = max((t), (v)))
#define updatemin(t, v) (t = min((t), (v)))
const int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
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
template <typename T>
class segtree {
 private:
  int n;
  vector<T> data, lazy;

 public:
  segtree(int n_) {
    n = pow(2, ceil(log2(n_)));
    data.resize(n);
    lazy.resize(n);
    auto __x = data[0];
    repi(n) {
      data[i] = __vmin(__x);
      lazy[i] = 0;
    }
  }
};

ll re(int lv, ll x) {
  if (x <= 0) return 0;
  if (lv <= 0) return 1;
  ll height = pow(2ll, lv + 2) - 3;
  if (x >= height - 1) return pow(2ll, lv + 1) - 1;
  if (x <= height / 2) return re(lv - 1, x - 1);
  if (x == height / 2 + 1) return pow(2ll, lv);
  return pow(2ll, lv) + re(lv - 1, x - (height / 2 + 1));
}
int main() {
  int n;
  ll x;
  cin >> n >> x;
  cout << re(n, x) << endl;
}
