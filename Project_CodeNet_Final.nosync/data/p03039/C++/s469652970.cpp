#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> bool cmax(T& a, U b) { if (a<b) {a = b; return true;} else return false; }
template<class T, class U> bool cmin(T& a, U b) { if (a>b) {a = b; return true;} else return false; }

template <uint_fast64_t Mod>
struct modint {
  using u64 = uint_fast64_t;
  u64 n;

  modint(const u64 x = 0) : n(x % Mod) {}
  modint operator+(const modint r) const { return modint(*this) += r; }
  modint operator-(const modint r) const { return modint(*this) -= r; }
  modint operator*(const modint r) const { return modint(*this) *= r; }
  modint operator/(const modint r) const { return modint(*this) /= r; }
  modint &operator+=(const modint r) {
    n += r.n;
    if (n >= Mod) n -= Mod;
    return *this;
  }
  modint &operator-=(const modint r) {
    if (n < r.n) n += Mod;
    n -= r.n;
    return *this;
  }
  modint &operator*=(const modint r) {
    n = n * r.n % Mod;
    return *this;
  }
  modint &operator/=(const modint r) { return *this *= r.inv(); }
  modint pow(u64 x) const {
    modint<Mod> ret(1), tmp(*this);
    while (x) {
      if (x&1) ret *= tmp;
      tmp *= tmp;
      x >>= 1;
    }
    return ret;
  }
  modint inv() const { return pow(Mod-2); }
  friend ostream& operator<<(ostream& os, const modint& obj) { return os << obj.n; }
  friend istream& operator>>(istream& is, modint& obj) { return is >> obj.n; }
};
constexpr ll mod = 1000000007;
using mint = modint<mod>;

// T modint
template<class T>
struct Combination {
  vector<T> fact, inv_fact;
  Combination(ll n) : fact(n+1), inv_fact(n+1) {
    fact[0] = T(1);
    for (ll i = 1; i <= n; i++) fact[i] = fact[i-1] * static_cast<T>(i);
    inv_fact[n] = fact[n].inv();
    for (ll i = n; i > 0; i--) inv_fact[i-1] = inv_fact[i] * static_cast<T>(i);
  }

  T P(ll n, ll k) const {
    return fact[n] * inv_fact[n-k];
  }

  T C(ll n, ll k) const {
    return fact[n] * inv_fact[n-k] * inv_fact[k];
  }

  T H(ll n, ll k) const {
    return C(n+k-1, n-1);
  }
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  ll k;
  mint n, m;
  cin >> n >> m >> k;
  mint ans(0);
  Combination<mint> comb(n.n*m.n);
  rep(i, n.n) {
    mint dis(i);
    ans += dis * m*m * (n-dis) * comb.C(n.n*m.n-2, k-2);
  }
  rep(i, m.n) {
    mint dis(i);
    ans += dis * n*n * (m-dis) * comb.C(n.n*m.n-2, k-2);
  }
  cout << ans << endl;

}









































