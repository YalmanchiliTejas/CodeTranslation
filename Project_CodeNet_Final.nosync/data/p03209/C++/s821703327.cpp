#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using std::string;
using std::vector;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::multimap;
using std::unordered_map;
using std::pair;
using std::cin;
using std::cout;

using boost::multiprecision::cpp_int;
using cpp_dec_float_1000 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>>;

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

constexpr char CRLF  = '\n';
constexpr char SPACE = ' ';
constexpr char VECTOR_COUT_SEPARATOR = SPACE;
constexpr ll INF = 1000'000'007;
constexpr int MOD = 1000'000'007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& vc) { for(auto it = vc.begin(); it != vc.end(); ++it) { if (std::next(it) == vc.end()) os << *it; else os << *it << VECTOR_COUT_SEPARATOR; } return os; }
template<class T1, class T2> inline std::ostream & operator<< (std::ostream & os, const std::pair<T1, T2> & p) { return os << p.first << ' ' << p.second; }
template<class T> T modinv(T a, T m) { T b = m, u = 1, v = 0; while (b) { T t = a / b; a -= t * b; boost::swap(a, b); u -= t * v; boost::swap(u, v); } u %= m; if (u < 0) u += m; return u; }

struct Tmp
{
public:
  Tmp(int N);
  // vector<vector<ll>> f;
  vector<ll> g,h;
  ll recF(ll n, ll x);
  ll recG(ll n);
  ll recH(ll n);
};

Tmp::Tmp(int N)
  : g(N+1, -1)
  , h(N+1, -1)
{}

ll Tmp::recF(ll n, ll x)
{
  if (n == 0) {
    return 1;
  }

  if (1 == x) {
    return 0;
  }
  else if (1 < x && x <= recG(n-1) + 1 ) {
    return recF(n-1, x-1);
  }
  else if (x == recG(n-1) + 2) {
    return recH(n-1) + 1;
  }
  else if (recG(n-1) + 2 < x && x < recG(n)) {
    return recH(n-1) + 1 + recF(n-1, x-2-recG(n-1));
  }
  else if (x == recG(n)) {
    return 2 * recH(n-1) + 1;
  }
  else {
    assert(false);
  }
}

ll Tmp::recG(ll n)
{
  if (g[n] != -1) {
    return g[n];
  }
  if (n == 0) {
    return g[n] = 1;
  }
  return g[n] = 2 * recG(n-1) + 3;
}

ll Tmp::recH(ll n)
{
  if (h[n] != -1) {
    return h[n];
  }
  if (n == 0) {
    return h[n] = 1;
  }
  return h[n] = 2 * recH(n-1) + 1;
}

void solve(void)
{
  int N;
  ll X;
  cin >> N >> X;
  Tmp t(N);
  auto ans = t.recF(N, X);
  cout << ans << CRLF;
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
