#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

// modint
template <int MOD>
struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Fp operator-() const noexcept { return val ? MOD - val : 0; }
  constexpr Fp operator+(const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator-(const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator*(const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator/(const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator+=(const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator-=(const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator*=(const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator/=(const Fp& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator==(const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator!=(const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator<<(ostream& os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD>& a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};

// binomial coefficient
template <class T>
struct BiCoef {
  vector<T> fact_, inv_, finv_;
  constexpr BiCoef() {}
  constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
    init(n);
  }
  constexpr void init(int n) noexcept {
    fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
    int MOD = fact_[0].getmod();
    for (int i = 2; i < n; i++) {
      fact_[i] = fact_[i - 1] * i;
      inv_[i] = -inv_[MOD % i] * (MOD / i);
      finv_[i] = finv_[i - 1] * inv_[i];
    }
  }
  constexpr T com(int n, int k) const noexcept {
    if (n < k || n < 0 || k < 0) return 0;
    if (n <= (int)fact_.size() - 1) {
      return fact_[n] * finv_[k] * finv_[n - k];
    }
    // C(n,k), n <= 1e9, k <= 1e6
    T res = 1;
    for (int i = n; i >= n - k + 1; i--) {
      T a = i;
      res *= a;
    }
    res *= finv_[k];
    return res;
  }
  constexpr T fact(int n) const noexcept {
    if (n < 0) return 0;
    return fact_[n];
  }
  constexpr T inv(int n) const noexcept {
    if (n < 0) return 0;
    return inv_[n];
  }
  constexpr T finv(int n) const noexcept {
    if (n < 0) return 0;
    return finv_[n];
  }
};

const int MOD = 1000000007;
// const int MOD = 998244353;
using mint = Fp<MOD>;
BiCoef<mint> bc;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  mint sum = 0, sSum = 0;
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
    sSum += a[i] * a[i];
  }
  mint ans = sum * sum - sSum;
  ans /= 2;
  cout << ans << endl;
}