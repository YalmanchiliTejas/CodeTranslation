#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define repi(n) for (int i = 0; i < n; i++)
#define repj(n) for (int j = 0; j < n; j++)
#define repk(n) for (int k = 0; j < n; k++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
#define repv(itr) for (auto&& v : itr)
#define swap(x, y)    \
  {                   \
    auto ___temp = x; \
    x = y;            \
    y = ___temp;      \
  }

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
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int n, h[20];
  cin >> n;
  repi(n) cin >> h[i];
  int re = 1;
  repr(i, 1, n) {
    repj(i) if (h[j] > h[i]) goto cont;
    re++;
  cont:
    0;
  }
  cout << re << endl;
}
