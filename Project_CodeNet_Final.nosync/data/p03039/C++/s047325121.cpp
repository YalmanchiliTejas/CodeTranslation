#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> void cmax(T& a, U b) { if (a<b) a = b; }
template<class T, class U> void cmin(T& a, U b) { if (a>b) a = b; }

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
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
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

const ll MOD = 1000000007;

vector<ll> fac;
vector<ll> ifac;

ll modpow(ll a, ll n, ll p) {
  ll res = 1;
  while (n) {
    if (n&1) res = res * a % p;
    a = a * a % p;
    n >>= 1;
  }
  return res;
}
 
void combinit(ll n) {
  fac.resize(n+1);
  ifac.resize(n+1);
 
  fac[0] = ifac[0] = 1;
  rep(i, n) {
    fac[i+1] = fac[i]*(i+1) % MOD;
    ifac[i+1] = ifac[i]*modpow(i+1, MOD-2, MOD) % MOD;
  }
}
 
ll comb(ll n, ll k) {
  if (n == 0 && k == 0) return 1;
  if (n < k || n < 0) return 0;
  return (fac[n]*ifac[k]%MOD)*ifac[n-k]%MOD;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  using mint = modint<MOD>;
  mint n, m;
  int k;
  cin >> n.a >> m.a >> k;

  int a = n.a*m.a;

  combinit(a);

  mint ans = 0;
  for (mint d = 0; d.a < n.a; d.a++) {
    ans += d * (n-d) * m*m * comb(a-2, k-2);
  }

  for (mint d = 0; d.a < m.a; d.a++) {
    ans += d * (m-d) * n*n * comb(a-2, k-2);
  }

  cout << ans.a << endl;
}
