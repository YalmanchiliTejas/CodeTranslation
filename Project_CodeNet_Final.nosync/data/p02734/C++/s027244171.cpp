#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

const int MOD_TYPE = 2;
const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-11;

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#pragma endregion

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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  ll n, s;
  cin >> n >> s;
  ll a[3010];
  rep(i, n) cin >> a[i];

  mint dp[3010][3010];
  rep(i, n) dp[i][0] = 1;
  rep(i, n)
  {
    rep(j, s + 1)
    {
      dp[i + 1][j] += dp[i][j];
      if (j + a[i] < 3010)
        dp[i + 1][j + a[i]] += dp[i][j];
    }
  }
  mint sum = 0;
  rep(i, n + 1)
  {
    sum += dp[i][s];
  }
  cout << sum << endl;
  return 0;
}