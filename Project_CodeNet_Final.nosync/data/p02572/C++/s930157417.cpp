#define MOD_TYPE 1

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;

#if 0
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using Int = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
#endif

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
//constexpr ll MOD = 1;
constexpr int INF = (int)1e9 + 10;
constexpr ll LINF = (ll)4e18;
constexpr double PI = acos(-1.0);
constexpr double EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

struct init_main
{
  init_main()
  {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(30) << setiosflags(ios::fixed);
  };
} init_main_;
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
template <typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val)
{
  fill((T *)array, (T *)(array + N), val);
}
template <typename T, typename U>
constexpr istream &operator>>(istream &is, pair<T, U> &p) noexcept
{
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
constexpr ostream &operator<<(ostream &os, pair<T, U> &p) noexcept
{
  os << p.first << " " << p.second;
  return os;
}
#pragma endregion

#pragma region mint
template <int MOD>
struct Fp
{
  long long val;

  constexpr Fp(long long v = 0) noexcept : val(v % MOD)
  {
    if (val < 0)
      v += MOD;
  }

  constexpr int getmod()
  {
    return MOD;
  }

  constexpr Fp operator-() const noexcept
  {
    return val ? MOD - val : 0;
  }

  constexpr Fp operator+(const Fp &r) const noexcept
  {
    return Fp(*this) += r;
  }

  constexpr Fp operator-(const Fp &r) const noexcept
  {
    return Fp(*this) -= r;
  }

  constexpr Fp operator*(const Fp &r) const noexcept
  {
    return Fp(*this) *= r;
  }

  constexpr Fp operator/(const Fp &r) const noexcept
  {
    return Fp(*this) /= r;
  }

  constexpr Fp &operator+=(const Fp &r) noexcept
  {
    val += r.val;
    if (val >= MOD)
      val -= MOD;
    return *this;
  }

  constexpr Fp &operator-=(const Fp &r) noexcept
  {
    val -= r.val;
    if (val < 0)
      val += MOD;
    return *this;
  }

  constexpr Fp &operator*=(const Fp &r) noexcept
  {
    val = val * r.val % MOD;
    if (val < 0)
      val += MOD;
    return *this;
  }

  constexpr Fp &operator/=(const Fp &r) noexcept
  {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b)
    {
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0)
      val += MOD;
    return *this;
  }

  constexpr bool operator==(const Fp &r) const noexcept
  {
    return this->val == r.val;
  }

  constexpr bool operator!=(const Fp &r) const noexcept
  {
    return this->val != r.val;
  }

  friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept
  {
    return os << x.val;
  }

  friend constexpr istream &operator>>(istream &is, Fp<MOD> &x) noexcept
  {
    return is >> x.val;
  }
};

Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept
{
  if (n == 0)
    return 1;
  auto t = modpow(a, n / 2);
  t = t * t;
  if (n & 1)
    t = t * a;
  return t;
}

using mint = Fp<MOD>;
#pragma endregion

void solve()
{
  int n;
  cin >> n;
  vector<mint> a(n);
  rep(i, n) cin >> a[i];
  mint sum = 0, ans = 0;
  rep(i, n)
  {
    ans += a[i] * sum;
    sum += a[i];
  }
  cout << ans << "\n";
}

int main()
{
  solve();
}
