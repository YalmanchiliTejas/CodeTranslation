#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define EPS (1e-7)
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define pii pair<int, int>
#define pll pair<long long, long long>
const double PI = acos(-1);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////

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

using mint = modint<MOD>;

struct ModCombination {
    vector<mint> Fac;
    vector<mint> Facinv;

    ModCombination(int x) {
        Fac.assign(x+1,1);
        Facinv.resize(x+1);
        for (long long i = 1; i <= x; i++) Fac[i] = Fac[i-1]*i;
        for (int i = 0; i <= x; i++) Facinv[i] = mint(1)/Fac[i];
    }

    mint get(int n, int k) {
        return Fac[n]*Facinv[k]*Facinv[n-k];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll N,M,K; cin >> N >> M >> K;

    ModCombination MC(N*M);

    mint cntN = 0;
    mint cntM = 0;
    for (ll i = 1; i <= N; i++) cntN += (i-1LL)*i;
    for (ll i = 1; i <= N; i++) cntN -= i*(N-i);
    for (ll i = 1; i <= M; i++) cntM += (i-1LL)*i;
    for (ll i = 1; i <= M; i++) cntM -= i*(M-i);
    cntN *= M*M;
    cntM *= N*N;
    mint ans = (cntN+cntM)*MC.get(N*M-2,K-2);

    cout << ans.a << endl;
}