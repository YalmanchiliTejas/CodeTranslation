#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U> void cmax(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void cmin(T &a, U b) { if (a > b) a = b; }

template<unsigned int mod> class modint {
private:
  unsigned int v;
  static unsigned int norm(const unsigned int &x) { return x < mod ? x : x - mod; }
  static modint make(const unsigned int &x) { modint m; return m.v = x, m; }
  static modint inv(const modint &x) { return make(inverse(x.v, mod)); }
  static unsigned int inverse(int a, int m) {
    int u[] = {a, 1, 0}, v[] = {m, 0, 1}, t;
    while (*v) {
      t = *u / *v;
      swap(u[0] -= t * v[0], v[0]), swap(u[1] -= t * v[1], v[1]), swap(u[2] -= t * v[2], v[2]);
    }
    return (u[1] % m + m) % m;
  }
public:
  modint() : v{0}{}
  modint(const long long val) : v{norm(val % mod + mod)} {}
  modint(const modint<mod>& n) : v{n()} {}
  explicit operator bool() const noexcept { return v != 0; }
  bool operator!() const noexcept { return !static_cast<bool>(*this); }
  modint& operator=(const modint& n) { return v = n(), (*this); }
  modint& operator=(const long long val) { return v = norm(val % mod + mod), (*this); }
  modint operator+() const { return *this; }
  modint operator-() const { return v == 0 ? make(0) : make(mod - v); }
  modint operator+(const modint& val) const { return make(norm(v + val())); }
  modint operator-(const modint& val) const { return make(norm(v + mod - val())); }
  modint operator*(const modint& val) const { return make((long long)v * val() % mod); }
  modint operator/(const modint& val) const { return *this * inv(val); }
  modint& operator+=(const modint& val) { return *this = *this + val; }
  modint& operator-=(const modint& val) { return *this = *this - val; }
  modint& operator*=(const modint& val) { return *this = *this * val; }
  modint& operator/=(const modint& val) { return *this = *this / val; }
  modint operator+(const long long val) const { return modint{v + val}; }
  modint operator-(const long long val) const { return modint{v - val}; }
  modint operator*(const long long val) const { return modint{(long long)(v * (val % mod))}; }
  modint operator/(const long long val) const { return modint{(long long)v * inv(val)}; }
  modint& operator+=(const long long val) { return *this = *this + val; }
  modint& operator-=(const long long val) { return *this = *this - val; }
  modint& operator*=(const long long val) { return *this = *this * val; }
  modint& operator/=(const long long val) { return *this = *this / val; }
  bool operator==(const modint& val) const { return v == val.v; }
  bool operator!=(const modint& val) const { return !(*this == val); }
  bool operator==(const long long val) const { return v == norm(val % mod + mod); }
  bool operator!=(const long long val) const { return !(*this == val); }
  unsigned int operator()() const { return v; }
  friend modint operator+(const long long val, const modint& n) { return n + val; }
  friend modint operator-(const long long val, const modint& n) { return modint{val - n()}; }
  friend modint operator*(const long long val, const modint& n) { return n * val; }
  friend modint operator/(const long long val, const modint& n) { return modint{val} / n; }
  friend bool operator==(const long long val, const modint& n) { return n == val; }
  friend bool operator!=(const long long val, const modint& n) { return !(val == n); }
  friend istream& operator>>(istream& is, modint& n) {
    unsigned int v;
    return is >> v, n = v, is;
  }
  friend ostream& operator<<(ostream& os, const modint& n) { return (os << n()); }
  friend modint mod_pow(modint x, long long n) {
    modint ans = 1;
    while (n) {
      if (n & 1) ans *= x;
      x *= x, n >>= 1;
    }
    return ans;
  }
};

constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
using mint = modint<MOD>;

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<mint> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  mint ans = 0, sum = 0;
  for (int i = 0; i < N; i++) {
    ans += A.at(i) * sum;
    sum += A.at(i);
  }
  cout << ans << "\n";
}