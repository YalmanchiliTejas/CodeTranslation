#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;


template<int MOD> class Modular {
public:
  long long value;
  constexpr Modular() : value() {};
  constexpr Modular(const Modular& other) : value(other.value) {}
  template <typename U> Modular(const U& x) { value = normalize(x); }
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
  constexpr Modular& operator=(const Modular& other) & noexcept { value = other.value; return *this; }
  template <typename U> constexpr Modular& operator=(const U& other) & noexcept { return *this = Modular(other); }

  constexpr Modular& operator+=(const Modular& other) noexcept { if ((value += other.value) >= MOD) value -= MOD; return *this; }
  template <typename U> constexpr Modular& operator+=(const U& other) noexcept { return *this += Modular(other); }

  constexpr Modular& operator-=(const Modular& other) noexcept { if ((value -= other.value) < 0) value += MOD; return *this; }
  template <typename U> constexpr Modular& operator-=(const U& other) noexcept { return *this -= Modular(other); }

  constexpr Modular& operator*=(const Modular& other) noexcept { value = value * other.value % MOD; return *this; }
  template <typename U> constexpr Modular& operator*=(const U& other) noexcept {return *this *= Modular(other); }

  constexpr Modular& operator/=(const Modular& other) noexcept { return *this *= Modular(inverse(other.value, MOD)); }
  template <typename U> constexpr Modular& operator/=(const U& other) noexcept { return *this *= Mudular(inverse(normalize(other.value))); }

  constexpr Modular& operator++() noexcept {return *this += 1; }
  constexpr Modular operator++(int) noexcept { Modular ret(*this); *this += 1; return ret; }

  constexpr Modular& operator--() noexcept {return *this -= 1; }
  constexpr Modular operator--(int) noexcept { Modular ret(*this); *this += 1; return ret; }

  constexpr Modular operator-() const { return Modular(-value); }

  constexpr int getmod() const { return MOD; }
};

template <int MOD> constexpr bool operator==(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return lhs.value == rhs.value; }
template <int MOD, typename U> constexpr bool operator==(const Modular<MOD>& lhs, U rhs) noexcept { return lhs == Modular<MOD>(rhs); }
template <int MOD, typename U> constexpr bool operator==(U lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) == rhs; }

template <int MOD> constexpr bool operator!=(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return !(lhs == rhs); }
template <int MOD, typename U> constexpr bool operator!=(const Modular<MOD>& lhs, U rhs) noexcept { return !(lhs == rhs); }
template <int MOD, typename U> constexpr bool operator!=(U lhs, const Modular<MOD> rhs) noexcept { return !(lhs == rhs); }

template <int MOD> constexpr bool operator<(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return lhs.value < rhs.value; }
template <int MOD, typename U> constexpr bool operator<(const Modular<MOD> &lhs, U rhs) noexcept { return lhs.value < rhs; }
template <int MOD, typename U> constexpr bool operator<(U lhs, const Modular<MOD> &rhs) noexcept { return lhs < rhs.value; }

template <int MOD> constexpr bool operator>(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return rhs.value < lhs.value; }
template <int MOD, typename U> constexpr bool operator>(const Modular<MOD> &lhs, U rhs) noexcept { return rhs.value < lhs; }
template <int MOD, typename U> constexpr bool operator>(U lhs, const Modular<MOD> &rhs) noexcept { return rhs < lhs.value; }

template <int MOD> constexpr bool operator<=(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return !(lhs.value > rhs.value); }
template <int MOD, typename U> constexpr bool operator<=(const Modular<MOD> &lhs, U rhs) noexcept { return !(lhs.value > rhs); }
template <int MOD, typename U> constexpr bool operator<=(U lhs, const Modular<MOD> &rhs) noexcept { return !(lhs < rhs.value); }

template <int MOD> constexpr bool operator>=(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return !(lhs.value < rhs.value); }
template <int MOD, typename U> constexpr bool operator>=(const Modular<MOD> &lhs, U rhs) noexcept { return !(lhs.value < rhs); }
template <int MOD, typename U> constexpr bool operator>=(U lhs, const Modular<MOD> &rhs) noexcept { return !(lhs < rhs.value); }

template <int MOD> constexpr Modular<MOD> operator+(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) += rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator+(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) += rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator+(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) += rhs; }

template <int MOD> constexpr Modular<MOD> operator-(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) -= rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator-(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) -= rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator-(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) -= rhs; }

template <int MOD> constexpr Modular<MOD> operator*(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) *= rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator*(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) *= rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator*(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) *= rhs; }

template <int MOD> constexpr Modular<MOD> operator/(const Modular<MOD>& lhs, const Modular<MOD>& rhs) noexcept { return Modular<MOD>(lhs) /= rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator/(const Modular<MOD>& lhs, U rhs) noexcept { return Modular<MOD>(lhs) /= rhs; }
template <int MOD, typename U> constexpr Modular<MOD> operator/(U lhs, const Modular<MOD> &rhs) noexcept { return Modular<MOD>(lhs) /= rhs; }

template<int MOD> std::ostream& operator<<(std::ostream& stream, const Modular<MOD>& number) noexcept { return stream << number.value; }
template<int MOD> std::istream& operator>>(std::istream& stream, Modular<MOD>& number) { long long in; stream >> in; number.value = Modular<MOD>::normalize(in); return stream; }

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
  constexpr BinaryCoefficients(int n = 202020) : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
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
using mint = Modular<mod>;
using bicoef = BinaryCoefficients<mod>;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
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