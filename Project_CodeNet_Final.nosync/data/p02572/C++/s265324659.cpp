#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> PLL;

// {{{ Modint
// mint x = 2;
// mint y = mint::P(5, 2);
// std::cout << x.a << std::endl;
template <std::int64_t M>
class modint {
 public:
  int64_t a;
  static std::vector<modint> fact;
  static std::vector<modint> inv_fact;
  explicit constexpr modint(const int64_t x = 0) noexcept :
    a((x % M + M) % M) {}
  constexpr int64_t &value() noexcept { return a; }
  constexpr const int64_t &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= M) {
      a -= M;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += M;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % M;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    int64_t exp = M - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
  constexpr modint pow(ll t) const {
    if (!t) return modint(1);
    modint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  static modint P(ll n, ll k) {
    if (fact.size() == 0) {
      const ll T = 3000000;
      fact.resize(T, modint(1));
      inv_fact.resize(T, modint(1));
      for (ll i = 2; i < T; i++) fact[i] = fact[i-1] * modint(i);
      for (ll i = 2; i < T; i++) inv_fact[i] = inv_fact[i-1] / modint(i);
    }
    if (n < k) return modint(0);
    if (n < 0 || k < 0) return modint(0);
    return fact[n] * inv_fact[n - k];
  }

  static modint C(ll n, ll k) {
    if (n < k) return modint(0);
    if (n < 0 || k < 0) return modint(0);
    return P(n, k) * inv_fact[k];
  }
};
template <std::int64_t M>
std::vector<modint<M>> modint<M>::fact;
template <std::int64_t M>
std::vector<modint<M>> modint<M>::inv_fact;
// }}}

using mint = modint<1000000007>;
void solve() {
  ll N;
  cin >> N;
  vector<mint> a(N);
  rep(i, N) {
    ll x;
    cin >> x;
    a[i] = mint(x);
  }
  mint ans(0);
  auto p = a[0];
  for (ll i = 1; i < N; i++) {
    ans += p * a[i];
    p += a[i];
  }
  cout << ans.value() << endl;
}

int main() {
  //ll T;
  //cin >> T;
  //rep(_,T)
    solve();
  return 0;
}
