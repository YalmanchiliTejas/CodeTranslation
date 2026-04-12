#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define all(c) (c).begin(), (c).end()
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef tuple<int, int> tii;
template <typename T>
ostream &operator<<(ostream &os, set<T> const &s);
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> const &mp);
template <typename T>
ostream &operator<<(ostream &os, vector<T> const &v);
template <typename... Types>
ostream &operator<<(ostream &os, tuple<Types...> const &v);
template <typename T>
ostream &operator<<(ostream &os, set<T> const &s);
template <typename T>
ostream &operator<<(ostream &os, set<T> const &s) {
  if (s.size() == 0) return os << "{}";
  os << "{";
  decltype(s.begin()) iter;
  for (iter = s.begin(), ++iter; iter != s.end(); ++iter) {
    --iter;
    os << *iter << ", ";
    ++iter;
  }
  --iter;
  os << *iter << '}';
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> const &mp) {
  if (mp.size() == 0) return os << "{}";
  os << "{" << endl;
  decltype(mp.begin()) iter;
  for (iter = mp.begin(), ++iter; iter != mp.end(); ++iter) {
    --iter;
    os << "  {" << iter->first << ", " << iter->second << "}," << endl;
    ++iter;
  }
  --iter;
  os << "  {" << iter->first << ", " << iter->second << "}" << endl << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> const &v) {
  os << '[';
  rep(i, v.size() - 1) os << v[i] << ", ";
  if (v.size() > 0) os << v[v.size() - 1];
  cerr << ']';
  return os;
}
template <typename T, unsigned N, unsigned Last>
struct TuplePrinter {
  static void print(ostream &os, T const &v) {
    os << std::get<N>(v) << ", ";
    TuplePrinter<T, N + 1, Last>::print(os, v);
  }
};
template <typename T, unsigned N>
struct TuplePrinter<T, N, N> {
  static void print(ostream &os, T const &v) { os << std::get<N>(v); }
};
template <typename... Types>
ostream &operator<<(ostream &os, tuple<Types...> const &v) {
  os << "(";
  TuplePrinter<tuple<Types...>, 0, sizeof...(Types) - 1>::print(os, v);
  os << ")";
  return os;
}
template <typename T>
void _dbg(T const &t) {
  cerr << t << endl;
}
template <typename T, typename... Args>
void _dbg(T const &t, Args... args) {
  cerr << t << " ";
  _dbg(args...);
}
template <typename... Args>
void __dbg(const char *fn, int l, Args... args) {
  cerr << "[" << fn << ":" << l << "] ";
  _dbg(args...);
}
#define dbg(...) __dbg(__func__, __LINE__, __VA_ARGS__)

const ll infty = 1223372036854775807;
const double eps = 1e-8;
const ll MOD = 1000000007LL;
const ll mod = MOD;

/*
ll modpow(ll x, ll n) {
  return n < 2 ? x : modpow(x * x, n / 2) * (n % 2 ? x : 1) % MOD;
}
ll modfact(ll n) { return n < 2 ? 1 : modfact(n - 1) * n % MOD; }
ll modcomb(ll n, ll r) {
  dbg(n, r);
  dbg(modfact(n - r), modpow(modfact(n - r), MOD - 3));
  return modfact(n) * modpow(modfact(r), MOD - 2) % MOD *
         modpow(modfact(n - r), MOD - 2) % MOD;
}
*/

long long modpow(long long x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long z = modpow(x, y / 2);
  z = z * z % mod;
  if (y % 2) z = z * x % mod;
  return z;
}

long long modinv(long long x) { return modpow(x, mod - 2); }

long long modfact(int n) {
  long long r = 1;
  for (int i = 1; i <= n; ++i) r = r * i % mod;
  return r;
}

long long modcomb(int n, int k) {
  return modfact(n) * modinv(modfact(k)) % mod * modinv(modfact(n - k)) % mod;
}

int main(int argc, char *argv[]) {
  // cin.tie(0); cout.sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  ll mult = modcomb(n * m - 2, k - 2);
  ll ans = 0;
  ll mm = m * m % MOD;
  ll nn = n * n % MOD;
  rep1(d, n - 1) {
    ll v = d * (n - d);
    v %= MOD;
    v *= mm;
    v %= MOD;
    ans += v;
    ans %= MOD;
  }
  rep1(d, m - 1) {
    ll v = d * (m - d);
    v %= MOD;
    v *= nn;
    v %= MOD;
    ans += v;
    ans %= MOD;
  }
  ans *= mult;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
