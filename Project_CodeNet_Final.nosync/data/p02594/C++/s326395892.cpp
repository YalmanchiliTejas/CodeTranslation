// #define MODULAR_ARITHMETIC
// #define INDEXED_SET

#pragma region
#ifndef LOCAL_DEBUG
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <assert.h>
#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define pb push_back
#define mp make_pair
#define f(i, a, b) for (int i = a; i < b; i++)
#define revf(i, b, a) for (int i = b; i >= a; i--)
#define srt(v) sort(v.begin(), v.end())
#define revsrt(v) sort(v.rbegin(), v.rend())
#define sp << ' ' <<
#define endl '\n'
#define precision(x) cout << fixed << setprecision(x);
#define fio                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<pair<T, T>> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++)
    os << "{" << v[i].first << ", " << v[i].second << "}\n";
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) os << v[i] << " ";
  os << endl;
  return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) is >> v[i];
  return is;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#ifdef MODULAR_ARITHMETIC
template <typename T>
T add(T a, T b, T c) {
  T res = a + b;
  return (res >= c ? res - c : res);
}
template <typename T>
T sub(T a, T b, T c) {
  T res = (a - b) % c;
  return (res < 0 ? res + c : res);
}
template <typename T>
T mul(T a, T b, T c) {
  ll res = (ll)a * b;
  return (res >= c ? res % c : res);
}
template <typename T>
T power(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <typename T>
T mod_inverse(T a, T n) {
  T x, y, zero = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : sub(x, zero, n));
}
#endif

#ifdef INDEXED_SET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
#endif
#pragma endregion

ll mod = 1e9 + 7;  // 998244353;
const int MAX = 1e5 + 5;

void preprocessing() {}

void solvetestcase() {
  ll n;
  cin >> n;
  cout << (n>=30 ? "Yes": "No") << endl;
}

int main() {
  fio;
  preprocessing();

  int t = 1;
  // UNCOMMENT FOR TESTCASES	\
	cin >> t;

  f(T, 1, t + 1) {
    // UNCOMMENT FOR CODEJAM,HACKERCUP	\
		cout << "Case #" << T << ": ";
    solvetestcase();
  }
};

/*
    AUTHOR:     KUNAL TAWATIA
    EDUCATION:  INDIAN INSTITUTE OF TECHNOLOGY, JODHPUR
*/