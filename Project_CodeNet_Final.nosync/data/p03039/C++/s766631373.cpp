#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

template <std::uint_fast64_t Modulus> class ModInt {
  using u64 = std::uint_fast64_t;

public:
  u64 x;

  constexpr ModInt(const u64 x = 0) noexcept : x(x % Modulus){};

  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt rhs) const noexcept {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    x += rhs.x;
    if (x >= Modulus) {
      x -= Modulus;
    }
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt rhs) noexcept {
    if (x < rhs.x) {
      x += Modulus;
    }
    x -= rhs.x;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    x = x * rhs.x % Modulus;
    return *this;
  }
  constexpr ModInt &operator/=(ModInt rhs) noexcept {
    u64 n = Modulus - 2;
    while (n) {
      if (n & 1) {
        *this *= rhs;
      }
      rhs *= rhs;
      n /= 2;
    }
    return *this;
  }
  constexpr ModInt operator++(int) noexcept {
    ModInt y = *this;
    x += 1;
    return y;
  }
  constexpr ModInt operator--(int) noexcept {
    ModInt y = *this;
    x -= 1;
    return y;
  }
  constexpr bool operator==(const ModInt rhs) noexcept { return x == rhs.x; }
  constexpr bool operator!=(const ModInt rhs) noexcept { return x != rhs.x; }

  friend std::istream &operator>>(std::istream &is, ModInt &rhs) {
    is >> rhs.x;
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &rhs) {
    os << rhs.x;
    return os;
  }
};

template <typename T> class Combination {
public:
  vector<T> f, invf;

  Combination(int n) : f(n + 1, 1), invf(n + 1, 1) {
    for (int i = 1; i < n + 1; i++) {
      f[i] = f[i - 1] * i;
    }
    invf[n] /= f[n];
    for (int i = n; i > 0; i--) {
      invf[i - 1] = invf[i] * i;
    }
  }

  T comb(int n, int r) {
    if (r < 0 || n < r) return 0;
    return f[n] * invf[r] * invf[n - r];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, K;
  cin >> N >> M >> K;
  using mint = ModInt<MOD>;
  Combination<mint> comb(N * M);
  mint sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      mint tmp = static_cast<mint>(N - i) * static_cast<mint>(M - j) *
                 static_cast<mint>(i + j);
      if (i != 0 && j != 0) tmp *= 2;
      sum += tmp;
    }
  }
  cout << sum * comb.comb(N * M - 2, K - 2) << '\n';
  return 0;
}
