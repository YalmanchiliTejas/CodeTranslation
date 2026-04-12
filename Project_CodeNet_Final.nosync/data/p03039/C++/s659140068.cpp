#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;


template<typename T> class Modular {
private:
  long long value;
  constexpr static int MOD() { return static_cast<int>(T::value); }
public:
  constexpr Modular() : value() {};
  constexpr Modular(const Modular& other) : value(other.value) {}
  template <typename U> constexpr Modular(const U& x) { value = normalize(x); }

  template <typename U> static long long normalize(const U& x) {
    long long v;
    if (-MOD() <= x && x < MOD()) v = static_cast<long long>(x);
    else v = static_cast<long long>(x % MOD());
    if (v < 0) v += MOD();
    return v;
  }

  constexpr static long long inverse(long long x) {
    x = normalize(x);
    long long y = MOD(), u = 1, v = 0;
    while(y) {
      long long t = x / y;
      x -= t * y; swap(x, y);
      u -= t * v; swap(u, v);
    }
    return normalize(u);
  }
  
  static long long mul(const long long& a, const long long& b) {
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
    res = a * b % MOD();
    #endif
    return res;
  }

  explicit operator long long() const noexcept { return value;}
  template <typename U> explicit operator U() const noexcept { return static_cast<U>(value); }

  constexpr Modular& operator=(const Modular& other) & noexcept { value = other.value; return *this; }
  template <typename U> constexpr Modular& operator=(const U& other) & noexcept { return *this = Modular(other); }

  constexpr Modular& operator+=(const Modular& other) noexcept { if ((value += other.value) >= MOD()) value -= MOD(); return *this; }
  template <typename U> constexpr Modular& operator+=(const U& other) noexcept { return *this += Modular(other); }

  constexpr Modular& operator-=(const Modular& other) noexcept { if ((value -= other.value) < 0) value += MOD(); return *this; }
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

  friend constexpr bool operator==(const Modular& lhs, const Modular<T>& rhs) noexcept { return lhs.value == rhs.value; }
  template <typename U> friend constexpr bool operator==(const Modular<T>& lhs, U rhs) noexcept { return lhs == Modular<T>(rhs); }
  template <typename U> friend constexpr bool operator==(U lhs, const Modular<T>& rhs) noexcept { return Modular<T>(lhs) == rhs; }

  friend constexpr bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return !(lhs == rhs); }
  template <typename U> friend constexpr bool operator!=(const Modular<T>& lhs, U rhs) noexcept { return !(lhs == rhs); }
  template <typename U> friend constexpr bool operator!=(U lhs, const Modular<T> rhs) noexcept { return !(lhs == rhs); }

  friend constexpr bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return lhs.value < rhs.value; }
  template <typename U> friend constexpr bool operator<(const Modular<T> &lhs, U rhs) noexcept { return lhs.value < rhs; }
  template <typename U> friend constexpr bool operator<(U lhs, const Modular<T> &rhs) noexcept { return lhs < rhs.value; }

  friend constexpr bool operator>(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return rhs.value < lhs.value; }
  template <typename U> friend constexpr bool operator>(const Modular<T> &lhs, U rhs) noexcept { return rhs.value < lhs; }
  template <typename U> friend constexpr bool operator>(U lhs, const Modular<T> &rhs) noexcept { return rhs < lhs.value; }

  friend constexpr bool operator<=(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return !(lhs.value > rhs.value); }
  template <typename U> friend constexpr bool operator<=(const Modular<T> &lhs, U rhs) noexcept { return !(lhs.value > rhs); }
  template <typename U> friend constexpr bool operator<=(U lhs, const Modular<T> &rhs) noexcept { return !(lhs < rhs.value); }

  friend constexpr bool operator>=(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return !(lhs.value < rhs.value); }
  template <typename U> friend constexpr bool operator>=(const Modular<T> &lhs, U rhs) noexcept { return !(lhs.value < rhs); }
  template <typename U> friend constexpr bool operator>=(U lhs, const Modular<T> &rhs) noexcept { return !(lhs < rhs.value); }

  friend constexpr Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return Modular<T>(lhs) += rhs; }
  template <typename U> friend constexpr Modular<T> operator+(const Modular<T>& lhs, U rhs) noexcept { return Modular<T>(lhs) += rhs; }
  template <typename U> friend constexpr Modular<T> operator+(U lhs, const Modular<T> &rhs) noexcept { return Modular<T>(lhs) += rhs; }

  friend constexpr Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return Modular<T>(lhs) -= rhs; }
  template <typename U> friend constexpr Modular<T> operator-(const Modular<T>& lhs, U rhs) noexcept { return Modular<T>(lhs) -= rhs; }
  template <typename U> friend constexpr Modular<T> operator-(U lhs, const Modular<T> &rhs) noexcept { return Modular<T>(lhs) -= rhs; }

  friend constexpr Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return Modular<T>(lhs) *= rhs; }
  template <typename U> friend constexpr Modular<T> operator*(const Modular<T>& lhs, U rhs) noexcept { return Modular<T>(lhs) *= rhs; }
  template <typename U> friend constexpr Modular<T> operator*(U lhs, const Modular<T> &rhs) noexcept { return Modular<T>(lhs) *= rhs; }

  friend constexpr Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) noexcept { return Modular<T>(lhs) /= rhs; }
  template <typename U> friend constexpr Modular<T> operator/(const Modular<T>& lhs, U rhs) noexcept { return Modular<T>(lhs) /= rhs; }
  template <typename U> friend constexpr Modular<T> operator/(U lhs, const Modular<T> &rhs) noexcept { return Modular<T>(lhs) /= rhs; }

  friend std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) noexcept { return stream << number.value; }
  friend std::istream& operator>>(std::istream& stream, Modular<T>& number) { long long in; stream >> in; number.value = Modular<T>::normalize(in); return stream; }
  
  constexpr int getmod() const { return MOD(); }
};

template<typename T, typename U> Modular<T> power(const Modular<T>& x, const U& y) {
  assert(y >= 0);
  Modular<T> k = x, result = 1;
  U p = y;
  while (p > 0) {
    if (p & 1) result *= k;
    k *= k;
    p >>= 1;
  }
  return result;
}

template<typename T> class BinaryCoefficients {
private:
  vector<Modular<T>> fact_, inv_, finv_;
  long long MOD = static_cast<long long>(T::value);
public:
  constexpr BinaryCoefficients(int n = 2020200) : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
    for (int i = 2; i < n; i++) {
      fact_[i] = fact_[i - 1] * i;
      inv_[i] = -inv_[MOD % i] * (MOD / i);
      finv_[i] = finv_[i - 1] * inv_[i];
    }
  }
  constexpr Modular<T> comb(int n, int k) const noexcept { if (n < k || n < 0 || k < 0) return 0; return fact_[n] * finv_[k] * finv_[n - k]; }
  constexpr Modular<T> fact(int n) const noexcept { if (n < 0) return 0; return fact_[n]; }
  constexpr Modular<T> inv(int n) const noexcept { if (n < 0) return 0; return inv_[n]; }
  constexpr Modular<T> finv(int n) const noexcept { if (n < 0) return 0; return finv_[n]; }
};

// constexpr int mod = 1e9 + 7;
// //constexpr int mod = 998244353;
// using mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;
// using bicoef = BinaryCoefficients<std::integral_constant<decay<decltype(mod)>::type, mod>>;

struct modValue { static int value; };
int modValue::value;
int& mod = modValue::value;
using mint = Modular<modValue>;
using bicoef = BinaryCoefficients<modValue>;

signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  mod = 1e9 + 7;
  bicoef bc;
  int n, m, k;
  cin >> n >> m >> k;
  mint tate = 0;
  for (mint i = 1; i < n; i++) {
    tate += i * (n - i);
  }
  tate *= m * m % mod;
  mint yoko = 0;
  for (mint i = 1; i < m; i++) {
    yoko += i * (m - i);
  }
  yoko *= n * n;
  cout << (yoko + tate) * bc.comb(n * m - 2, k - 2) << endl;
  return 0;
}
