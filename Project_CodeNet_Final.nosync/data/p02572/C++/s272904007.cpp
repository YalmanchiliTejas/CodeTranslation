#line 2 "/home/toof/working/library/template.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0; i < (ll)n; i++)
#define rep3(i, l, r) for(ll i = l; i < (ll)r; i++)
#define per(i, n) for(ll i = (ll)n-1; i >= 0; i--)
#define per3(i, l, r) for(ll i = (ll)r-1; i >= (ll)l; i--)
#define all(v) begin(v), end(v)
template<class T, class U> inline void cmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> inline void cmin(T &a, U b) { if (a > b) a = b; }
constexpr char el = '\n';
template<class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { rep(i, v.size()) os << v[i] << (i+1 != v.size() ? " " : ""); return os; }
template<class T> istream &operator>>(istream &is, vector<T> &v) { for(T &i : v) is >> i; return is; }
struct IoSetup {
  IoSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(15); }
} io_setup;
#line 3 "/home/toof/working/library/modint.hpp"

template <ll Mod>
struct ModInt {
  ll n;

  ModInt(const ll x = 0) : n(x) {
    while (n < 0) n += Mod;
    n %= Mod;
  }

  inline constexpr ModInt operator+(const ModInt r) const noexcept { return ModInt(*this) += r; }
  inline constexpr ModInt operator-(const ModInt r) const noexcept { return ModInt(*this) -= r; }
  inline constexpr ModInt operator*(const ModInt r) const noexcept { return ModInt(*this) *= r; }
  inline constexpr ModInt operator/(const ModInt r) const noexcept { return ModInt(*this) /= r; }
  inline constexpr ModInt &operator+=(const ModInt r) noexcept {
    n += r.n;
    if (n >= Mod) n -= Mod;
    return *this;
  }
  inline constexpr ModInt &operator-=(const ModInt r) noexcept {
    if (n < r.n) n += Mod;
    n -= r.n;
    return *this;
  }
  inline constexpr ModInt &operator*=(const ModInt r) noexcept {
    n = n * r.n % Mod;
    return *this;
  }
  inline constexpr ModInt &operator/=(const ModInt r) noexcept { return *this *= r.inv(); }

  inline constexpr ModInt pow(ll x) const noexcept {
    ModInt<Mod> ret(1), tmp(*this);
    while (x) {
      if (x&1) ret *= tmp;
      tmp *= tmp;
      x >>= 1;
    }
    return ret;
  }
  inline constexpr ModInt inv() const noexcept { return pow(Mod-2); }

  friend ostream& operator<<(ostream& os, const ModInt& obj) { return os << obj.n; }
  friend istream& operator>>(istream& is, ModInt& obj) {
    ll t;
    is >> t;
    obj = ModInt(t);
    return is;
  }
};

constexpr ll mod = 1000000007;
using mint = ModInt<mod>;
mint operator"" _mi(unsigned long long n) { return mint(n); }
#line 3 "/home/toof/working/library/cumulative_sum.hpp"

template<class T>
struct CumulativeSum {
  vector<T> v;

  CumulativeSum(size_t n) : v(n+1) {};
  CumulativeSum(vector<T> v_) {
    v.resize(v_.size()+1);
    rep(i, v_.size())
      v[i+1] = v_[i];
  };

  void add(size_t i, T x) {
    v[i+1] += x;
  }

  // O(N)
  void build() {
    if (v.size() == 0) return;
    rep(i, v.size()-1)
      v[i+1] += v[i];
  }

  // O(1) sum [l, r]
  T sum(size_t l, size_t r) const {
    return l == 0 ? v[r+1] : v[r+1]-v[l];
  }

  // O(1) sum [0, r]
  T sum(size_t r) const {
    return v[r+1];
  }

  T& operator[](size_t i) {
    return v[i];
  }

  const T& operator[](size_t i) const {
    return v[i];
  }
};
#line 4 "c.cpp"

int main() {
  ll n;
  cin >> n;
  vector<mint> a(n);
  cin >> a;

  vector<mint> c(n);
  per(i, n-1) {
    c[i] = a[i+1] + c[i+1];
  }

  mint ans = 0;
  rep(i, n) {
    ans += a[i] * c[i];
  }
  cout << ans << el;
}
