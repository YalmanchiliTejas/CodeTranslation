// Author: Tyler Wang

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

template <int Modulus>
class mod_int {
 public:
  constexpr mod_int() : val_(0) {}

  template <typename T>
  constexpr mod_int(T val) : val_((int)(val % Modulus)) {
    if (val_ < 0) {
      val_ += Modulus;
    }
  }

  static constexpr int modulus() { return Modulus; }

  template <typename T>
  constexpr explicit operator T() const {
    return (T)val_;
  }

  constexpr mod_int& operator++() {
    if (++val_ == Modulus) {
      val_ = 0;
    }
    return *this;
  }

  constexpr mod_int operator++(int) {
    mod_int t = *this;
    ++*this;
    return t;
  }

  constexpr mod_int& operator--() {
    if (val_ == 0) {
      val_ = Modulus;
    }
    --val_;
    return *this;
  }

  constexpr mod_int operator--(int) {
    mod_int t = *this;
    --*this;
    return t;
  }

  constexpr mod_int operator+=(mod_int other) {
    if ((val_ += other.val_) >= Modulus) {
      val_ -= Modulus;
    }
    return *this;
  }

  constexpr mod_int operator-=(mod_int other) {
    if ((val_ -= other.val_) < 0) {
      val_ += Modulus;
    }
    return *this;
  }

  constexpr mod_int operator*=(mod_int other) {
    val_ = (int)((long long)val_ * other.val_ % Modulus);
    return *this;
  }

  constexpr mod_int operator/=(mod_int other) { return *this *= inv(other); }

  friend constexpr mod_int operator+(mod_int mi) { return mi; }

  friend constexpr mod_int operator-(mod_int mi) {
    if (mi.val_ != 0) {
      mi.val_ = Modulus - mi.val_;
    }
    return mi;
  }

  friend constexpr mod_int operator+(mod_int lhs, mod_int rhs) {
    return lhs += rhs;
  }

  friend constexpr mod_int operator-(mod_int lhs, mod_int rhs) {
    return lhs -= rhs;
  }

  friend constexpr mod_int operator*(mod_int lhs, mod_int rhs) {
    return lhs *= rhs;
  }

  friend constexpr mod_int operator/(mod_int lhs, mod_int rhs) {
    return lhs /= rhs;
  }

  friend constexpr bool operator==(mod_int lhs, mod_int rhs) {
    return lhs.val_ == rhs.val_;
  }

  friend constexpr bool operator!=(mod_int lhs, mod_int rhs) {
    return lhs.val_ != rhs.val_;
  }

  friend constexpr bool operator<(mod_int lhs, mod_int rhs) {
    return lhs.val_ < rhs.val_;
  }

  friend constexpr bool operator<=(mod_int lhs, mod_int rhs) {
    return lhs.val_ <= rhs.val_;
  }

  friend constexpr bool operator>(mod_int lhs, mod_int rhs) {
    return lhs.val_ > rhs.val_;
  }

  friend constexpr bool operator>=(mod_int lhs, mod_int rhs) {
    return lhs.val_ >= rhs.val_;
  }

  friend std::ostream& operator<<(std::ostream& os, mod_int mi) {
    return os << mi.val_;
  }

  friend std::istream& operator>>(std::istream& is, mod_int& mi) {
    long long val;
    is >> val;
    mi = mod_int(val);
    return is;
  }

  friend constexpr mod_int inv(mod_int mi) {
    int a = mi.val_, b = Modulus;
    int x = 0, xx = 1;
    while (a != 0) {
      int q = b / a;
      int t = a;
      a = b - q * a;
      b = t;
      t = xx;
      xx = x - q * xx;
      x = t;
    }
    return mod_int(x);
  }

  template <typename T>
  friend constexpr mod_int pow(mod_int base, T expo) {
    if (expo < 0) {
      base = inv(base);
      expo = -expo;
    }
    mod_int power = 1;
    for (; expo != 0; expo >>= 1) {
      if (expo & 1) {
        power *= base;
      }
      base *= base;
    }
    return power;
  }

 private:
  int val_;
};

constexpr int MODULUS = 1'000'000'007;
using m_int = mod_int<MODULUS>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(12);
  std::cerr.precision(12);
  std::mt19937 rng((std::uint_fast32_t)std::chrono::high_resolution_clock::now()
                       .time_since_epoch()
                       .count());
  string k;
  int d;
  cin >> k >> d;
  vector<vector<m_int>> dp(d, vector<m_int>(2));
  dp[0][1] = 1;
  for (char c : k) {
    int up = c - '0';
    vector<vector<m_int>> next_dp(d, vector<m_int>(2));
    for (int i = 0; i < d; ++i) {
      for (int j = 0; j <= 9; ++j) {
        int x = (i + j) % d;
        next_dp[x][0] += dp[i][0];
        if (j < up) {
          next_dp[x][0] += dp[i][1];
        } else if (j == up) {
          next_dp[x][1] += dp[i][1];
        }
      }
    }
    dp = move(next_dp);
  }
  cout << dp[0][0] + dp[0][1] - 1 << '\n';
  return 0;
}