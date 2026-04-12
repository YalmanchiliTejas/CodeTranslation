/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

const int64_t kMod = 1000000007LL;
// const int64_t kMod = 998244353LL;
struct Mint {
  int64_t value;
  Mint(int64_t value = 0LL) : value((value % kMod + kMod) % kMod) {}
  Mint operator-() const {
    return Mint(-value);
  }
  Mint &operator+=(const Mint rhs) {
    if ((value += rhs.value) >= kMod) {
      value -= kMod;
    }
    return *this;
  }
  Mint &operator-=(const Mint rhs) {
    if ((value += kMod - rhs.value) >= kMod) {
      value -= kMod;
    }
    return *this;
  }
  Mint &operator*=(const Mint rhs) {
    (value *= rhs.value) %= kMod;
    return *this;
  }
  Mint operator+(const Mint rhs) const {
    return Mint(*this) += rhs;
  }
  Mint operator-(const Mint rhs) const {
    return Mint(*this) -= rhs;
  }
  Mint operator*(const Mint rhs) const {
    return Mint(*this) *= rhs;
  }
  Mint Pow(int64_t p) const {
    if (p == 0LL) {
      return 1LL;
    } else if (p < 0LL) {
      return Pow(-p).Pow(kMod - 2LL);
    }
    Mint temp = Pow(p >> 1LL);
    temp *= temp;
    if (p & 1LL) {
      temp *= (*this);
    }
    return temp;
  }
  Mint Inv() const {
    return Pow(kMod - 2LL);
  }
  Mint &operator/=(const Mint a) {
    return *this *= a.Inv();
  }
  Mint operator/(const Mint a) const {
    return Mint(*this) /= a;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  Mint S = 0;
  Mint SS = 0;
  cin >> N;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
    S += A[i];
    SS += A[i] * A[i];
  }
  Mint result = (S * S - SS) / 2;
  cout << result.value << endl;
  return 0;
}
