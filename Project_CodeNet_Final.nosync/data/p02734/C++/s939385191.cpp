#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v) do { x = max(x, v); } while (0)
#define chmin(x, v) do { x = min(x, v); } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

// {{{ Modint
// using mint = modint<1000000007>;
// mint x = 2;
// std::cout << x.a << std::endl;
template <std::int64_t M>
class modint {
 public:
  int64_t a;

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
};
// }}}
using mint = modint<998244353>;
ll N, S;
mint dp[5000][5000];
ll a[5000];

signed main() {
  cin >> N >> S;
  for (ll i = 1; i <= N; i++)
    cin >> a[i];
  rep(i, 5000) rep(j, 5000) dp[i][j] = mint(0);
  dp[0][0] = mint(1);
  rep(i, N) {
    ll ni = i+1;
    // ni番目から開始する
    dp[ni][0] += mint(1);
    rep(j, 5000) {
      // ni番目を追加しない
      dp[ni][j] += dp[i][j]; 
      // ni番目を追加する
      if (j + a[ni] < 5000)
        dp[ni][j + a[ni]] += dp[i][j];
    }
  }
  mint ans(0);
  for (ll i = 1; i <= N; i++){
    ans += dp[i][S];
  }
  cout << ans.value() << endl;
  return 0;
}
