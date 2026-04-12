#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_temp>
using smaller_queue = priority_queue<Q_temp, vector<Q_temp>, greater<Q_temp>>;

const ll MOD = (ll)(1e9 + 7);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const double PI = acos(-1.0);

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

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

template <class T>
struct BiCoef
{
  vector<T> fact_, inv_, finv_;

  constexpr BiCoef()
  {
  }

  constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1)
  {
    init(n);
  }

  constexpr void init(int n) noexcept
  {
    fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
    int MOD = fact_[0].getmod();
    for (int i = 2; i < n; i++)
    {
      fact_[i] = fact_[i - 1] * i;
      inv_[i] = -inv_[MOD % i] * (MOD / i);
      finv_[i] = finv_[i - 1] * inv_[i];
    }
  }

  constexpr T C(int n, int k) const noexcept
  {
    if (n < k || n < 0 || k < 0)
      return 0;
    return fact_[n] * finv_[k] * finv_[n - k];
  }

  constexpr T P(int n, int k) const noexcept
  {
    return C(n, k) * fact_[k];
  }

  constexpr T H(int n, int k) const noexcept
  {
    return C(n + k - 1, k);
  }

  constexpr T fact(int n) const noexcept
  {
    if (n < 0)
      return 0;
    return fact_[n];
  }

  constexpr T inv(int n) const noexcept
  {
    if (n < 0)
      return 0;
    return inv_[n];
  }

  constexpr T finv(int n) const noexcept
  {
    if (n < 0)
      return 0;
    return finv_[n];
  }
};

BiCoef<mint> bc(200010);

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << setiosflags(ios::fixed);
  ll n, m, k;
  cin >> n >> m >> k;
  mint Ex = 0, Ey = 0;
  for (ll i = 1; i <= m; i++)
    Ex += i * (m - i) * n * n;
  for (ll i = 1; i <= n; i++)
    Ey += i * (n - i) * m * m;
  Ex /= bc.C(m * n, 2);
  Ey /= bc.C(m * n, 2);
  mint E = Ex + Ey;
  mint E_all = E * k * (k - 1) / 2;
  cout << E_all * bc.C(n * m, k) << endl;
  return 0;
}
