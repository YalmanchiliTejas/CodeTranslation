#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
template<int MOD> class Modular {
private:
  long long value;
public:
  constexpr Modular() : value() {};
  constexpr Modular(const Modular& other) : value(other.value) {}
  template <typename U> constexpr Modular(const U& x) { value = normalize(x); }

  template <typename U> static long long normalize(const U& x) {
    long long v;
    if (-MOD <= x && x < MOD) v = static_cast<long long>(x);
    else v = static_cast<long long>(x % MOD);
    if (v < 0) v += MOD;
    return v;
  }

  constexpr long long inverse(long long x) {
    x = (x % MOD + MOD) % MOD;
    long long y = MOD, u = 1, v = 0;
    while(y) {
      long long t = x / y;
      x -= t * y; swap(x, y);
      u -= t * v; swap(u, v);
    }
    return (u % MOD + MOD) % MOD;
  }
  
  static long long mul(long long a, long long b) {
    long long res;
    #ifdef _WIN32
    unsigned long long x = a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (MOD)
    );
    res = m;
    #else
    res = a * b % MOD;
    #endif
    return res;
  }

  explicit operator long long() const noexcept { return value;}
  template <typename U> explicit operator U() const noexcept { return static_cast<U>(value); }

  constexpr Modular& operator=(const Modular& other) & noexcept { value = other.value; return *this; }
  template <typename U> constexpr Modular& operator=(const U& other) & noexcept { return *this = Modular(other); }

  constexpr Modular& operator+=(const Modular& other) noexcept { if ((value += other.value) >= MOD) value -= MOD; return *this; }
  template <typename U> constexpr Modular& operator+=(const U& other) noexcept { return *this += Modular(other); }

  constexpr Modular& operator-=(const Modular& other) noexcept { if ((value -= other.value) < 0) value += MOD; return *this; }
  template <typename U> constexpr Modular& operator-=(const U& other) noexcept { return *this -= Modular(other); }

  constexpr Modular& operator*=(const Modular& other) noexcept { this->value = mul(this->value, other.value); return *this; }
  template <typename U> constexpr Modular& operator*=(const U& other) noexcept {return *this *= Modular(other); }

  constexpr Modular& operator/=(const Modular& other) noexcept { return *this *= Modular(inverse(other.value)); }
  template <typename U> constexpr Modular& operator/=(const U& other) noexcept { return *this *= Modular(inverse(normalize(other))); }

  constexpr Modular& operator++() noexcept {return *this += 1; }
  constexpr Modular operator++(int) noexcept { Modular ret(*this); *this += 1; return ret; }

  constexpr Modular& operator--() noexcept {return *this -= 1; }
  constexpr Modular operator--(int) noexcept { Modular ret(*this); *this += 1; return ret; }

  constexpr Modular operator-() const { return Modular(-value); }

  friend constexpr bool operator==(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return lhs.value == rhs.value; }
  template <typename U> friend constexpr bool operator==(const Modular<MOD>& lhs, U rhs) noexcept { return lhs == Modular<MOD>(rhs); }
  template <typename U> friend constexpr bool operator==(U lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) == rhs; }

  friend constexpr bool operator!=(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return !(lhs == rhs); }
  template <typename U> friend constexpr bool operator!=(const Modular<MOD>& lhs, U rhs) noexcept { return !(lhs == rhs); }
  template <typename U> friend constexpr bool operator!=(U lhs, const Modular<MOD> rhs) noexcept { return !(lhs == rhs); }

  friend constexpr bool operator<(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return lhs.value < rhs.value; }
  template <typename U> friend constexpr bool operator<(const Modular<MOD> &lhs, U rhs) noexcept { return lhs.value < rhs; }
  template <typename U> friend constexpr bool operator<(U lhs, const Modular<MOD> &rhs) noexcept { return lhs < rhs.value; }

  friend constexpr bool operator>(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return rhs.value < lhs.value; }
  template <typename U> friend constexpr bool operator>(const Modular<MOD> &lhs, U rhs) noexcept { return rhs.value < lhs; }
  template <typename U> friend constexpr bool operator>(U lhs, const Modular<MOD> &rhs) noexcept { return rhs < lhs.value; }

  friend constexpr bool operator<=(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return !(lhs.value > rhs.value); }
  template <typename U> friend constexpr bool operator<=(const Modular<MOD> &lhs, U rhs) noexcept { return !(lhs.value > rhs); }
  template <typename U> friend constexpr bool operator<=(U lhs, const Modular<MOD> &rhs) noexcept { return !(lhs < rhs.value); }

  friend constexpr bool operator>=(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return !(lhs.value < rhs.value); }
  template <typename U> friend constexpr bool operator>=(const Modular<MOD> &lhs, U rhs) noexcept { return !(lhs.value < rhs); }
  template <typename U> friend constexpr bool operator>=(U lhs, const Modular<MOD> &rhs) noexcept { return !(lhs < rhs.value); }

  friend constexpr Modular<MOD> operator+(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) += rhs; }
  template <typename U> friend constexpr Modular<MOD> operator+(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) += rhs; }
  template <typename U> friend constexpr Modular<MOD> operator+(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) += rhs; }

  friend constexpr Modular<MOD> operator-(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) -= rhs; }
  template <typename U> friend constexpr Modular<MOD> operator-(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) -= rhs; }
  template <typename U> friend constexpr Modular<MOD> operator-(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) -= rhs; }

  friend constexpr Modular<MOD> operator*(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) *= rhs; }
  template <typename U> friend constexpr Modular<MOD> operator*(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) *= rhs; }
  template <typename U> friend constexpr Modular<MOD> operator*(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) *= rhs; }

  friend constexpr Modular<MOD> operator/(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) /= rhs; }
  template <typename U> friend constexpr Modular<MOD> operator/(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) /= rhs; }
  template <typename U> friend constexpr Modular<MOD> operator/(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) /= rhs; }

  friend std::ostream& operator<<(std::ostream& stream, const Modular<MOD>& number) noexcept { return stream << number.value; }
  friend std::istream& operator>>(std::istream& stream, Modular<MOD>& number) { long long in; stream >> in; number.value = Modular<MOD>::normalize(in); return stream; }
  
  constexpr int getmod() const { return MOD; }
};

template<int MOD, typename U> Modular<MOD> power(const Modular<MOD>& x, const U& y) {
  assert(y >= 0);
  Modular<MOD> k = x, result = 1;
  U p = y;
  while (p > 0) {
    if (p & 1) result *= k;
    k *= k;
    p >>= 1;
  }
  return result;
}

template<int MOD> class BinaryCoefficients {
private:
  vector<Modular<MOD>> fact_, inv_, finv_;
public:
  constexpr BinaryCoefficients(int n = 2020200) : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
    for (int i = 2; i < n; i++) {
      fact_[i] = fact_[i - 1] * i;
      inv_[i] = -inv_[MOD % i] * (MOD / i);
      finv_[i] = finv_[i - 1] * inv_[i];
    }
  }
  constexpr Modular<MOD> comb(int n, int k) const noexcept { if (n < k || n < 0 || k < 0) return 0; return fact_[n] * finv_[k] * finv_[n - k]; }
  constexpr Modular<MOD> fact(int n) const noexcept { if (n < 0) return 0; return fact_[n]; }
  constexpr Modular<MOD> inv(int n) const noexcept { if (n < 0) return 0; return inv_[n]; }
  constexpr Modular<MOD> finv(int n) const noexcept { if (n < 0) return 0; return finv_[n]; }
};

constexpr int mod = 1e9 + 7;
//constexpr int mod = 998244353;
using mint = Modular<mod>;
using bicoef = BinaryCoefficients<mod>;

mint dp[1010][1010];

signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  bicoef bc(2000);
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  dp[a - 1][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i + 1][j] += dp[i][j];
      for (int q = c; q <= d && j + (i + 1) * q <= n; q++) {
        dp[i + 1][j + (i + 1) * q] += dp[i][j] * bc.fact(n - j) * bc.finv(n - j - (i + 1) * q) * bc.finv(q) / power(bc.fact(i + 1), q);
      }
    }
  }
  cout << dp[b][n] << endl;
  return 0;
}