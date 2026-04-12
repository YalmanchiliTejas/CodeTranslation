#include <bits/stdc++.h>

using namespace std;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    u -= t * v;
    std::swap(a, m);
    std::swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = std::decay_t<decltype(T::value)>;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U &x) : value(normalize(x)) {}

  template <typename U>
  Type normalize(const U &x) {
    Type v;
    if (-mod <= x && x < mod) {
      v = static_cast<Type>(x);
    } else {
      v = static_cast<Type>(x % mod);
    }
    if (v < 0) v += mod;
    return v;
  }

  const Type &operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod = T::value;

  Modular &operator+=(const Modular &rhs) {
    if ((value += rhs.value) >= mod) value -= mod;
    return *this;
  }
  Modular &operator-=(const Modular &rhs) {
    if ((value -= rhs.value) < 0) value += mod;
    return *this;
  }

  template <typename U>
  Modular &operator+=(const U &rhs) {
    return *this += Modular(rhs);
  }
  template <typename U>
  Modular &operator-=(const U &rhs) {
    return *this -= Modular(rhs);
  }

  Modular &operator++() { return *this += 1; }
  Modular &operator--() { return *this -= 1; }

  Modular operator++(int) {
    Modular res(*this);
    *this += 1;
    return res;
  }
  Modular operator--(int) {
    Modular res(*this);
    *this -= 1;
    return res;
  }

  template <typename U = T>
  std::enable_if_t<std::is_same<typename Modular<U>::Type, int>::value, Modular> &operator*=(
      const Modular &rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  std::enable_if_t<std::is_same<typename Modular<U>::Type, int64_t>::value, Modular> &operator*=(
      const Modular &rhs) {
    value = normalize(static_cast<__int128>(value) * static_cast<__int128>(rhs.value));
    return *this;
  }

  Modular &operator/=(const Modular &rhs) { return *this *= Modular(inverse(rhs.value, mod)); }

  template <typename U>
  friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);
  template <typename U>
  friend bool operator>(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend std::istream &operator>>(std::istream &stream, Modular<U> &rhs);
  template <typename U>
  friend std::ostream &operator<<(std::ostream &stream, const Modular<U> &rhs);

 private:
  Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value < rhs.value;
}

template <typename T>
bool operator>(const Modular<T> &lhs, const Modular<T> &rhs) {
  return lhs.value > rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) {
  return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U n = b;
  while (n > 0) {
    if (n & 1) res *= x;
    x *= x;
    n >>= 1;
  }
  return res;
}

template <typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &rhs) {
  typename std::common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  rhs = Modular<T>(x);
  return stream;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &rhs) {
  stream << rhs.value;
  return stream;
}

constexpr int mod = 1000000007;
// constexpr int mod = 998244353;
using mint = Modular<std::integral_constant<std::decay_t<decltype(mod)>, mod>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &&e : A) {
    cin >> e;
  }
  mint sum = 0;
  for (auto &&e : A) {
    sum += e;
  }
  mint res = 0;
  for (auto &&e : A) {
    sum -= e;
    res += sum * e;
  }
  cout << res << '\n';
  return 0;
}
