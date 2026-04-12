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
using mint = modint<1000000007>;

// d[i][m][s]: 上からi桁まで見て、かつi桁番目までがKと m(atch) し総和がsとなる、場合の数
mint d[20000][2][200];
vector<ll> K;
ll D, N;

signed main() {
  string tmp;
  cin >> tmp >> D;
  N = tmp.size();
  K.resize(N);
  rep(i, N) {
    K[i] = tmp[i] - '0';
    // cout << "i=" << i << " Ki=" << K[i] << endl;
  }
  // cout<< "N=" << N << endl;

  // init
  rep(p, K[0]) {
    d[0][0][p%D] += mint(1);
  }
  d[0][1][K[0]%D] = mint(1);

  // process
  rep(i, N-1) rep(s, 200) {
    // for m=0
    {    
      rep(p, 10) {
        d[i+1][0][(s+p)%D] += d[i][0][s];
      }
    }
    // for m=1
    {
      rep(p, K[i+1]) {
        d[i+1][0][(s+p)%D] += d[i][1][s];
      }
      {
        ll p = K[i+1];
        d[i+1][1][(s+p)%D] += d[i][1][s];
      }
    }
  }
  //rep(i, N) rep(m, 2) rep(s, 200) {
  //  if (d[i][m][s].value() == 0) continue;
  //  printf("d[%ld][%ld][%ld] = %ld\n", i,m,s,d[i][m][s].value());
  //}

  mint ans(0);
  rep(m, 2) {
    ans += d[N-1][m][0];
  }
  ans -= mint(1); // 0...0 を引く
  cout << ans.value() << endl;
  return 0;
}
