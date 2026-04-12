/**
 *    author:  zjsdut
 *    created: 2020/03/23 11:14:30
 **/
#include <bits/stdc++.h>

using namespace std;

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

template <typename A, typename B> bool chkmin(A &a, const B &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template <typename A, typename B> bool chkmax(A &a, const B &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

template <typename T> istream &operator>>(istream &stream, vector<T> &vec) {
  for (auto &x : vec)
    stream >> x;
  return stream;
}

void scan() {}

template <class T, class... Args> void scan(T &a, Args &... rest) {
  cin >> a;
  scan(rest...);
}

using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;
using vi = vector<int>;
using pii = pair<int, int>;
template <typename T> using vv = vector<vector<T>>;
#define rng(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define up(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define down(i, b, a) for (int i = int(b); i >= int(a); i--)
#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define rep(n)                                                                 \
  for (int TOKENPASTE2(_iter_, __LINE__) = 0,                                  \
                               TOKENPASTE2(_num_, __LINE__) = (int)(n);        \
       TOKENPASTE2(_iter_, __LINE__) < TOKENPASTE2(_num_, __LINE__);           \
       ++TOKENPASTE2(_iter_, __LINE__))
#define FOR(x, cont) for (const auto &x : cont)
#define For(x, cont) for (auto &x : cont)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int)(x).size()
#define UNIQ(vec) (vec).erase(unique(all(vec)), end(vec))
#define LB(cont, x) int(lower_bound(all(cont), x) - begin(cont))
#define UB(cont, x) int(upper_bound(all(cont), x) - begin(cont))

template <typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec) {
  if (!vec.empty()) {
    stream << vec[0];
    for (size_t i = 1; i != vec.size(); ++i)
      stream << ' ' << vec[i];
  }
  return stream;
}

template <typename T> void print(const vector<T> &t) { cout << t << '\n'; }

template <typename T> void print(const vector<vector<T>> &t) {
  for (const auto &row : t) {
    print(row);
  }
}

template <typename T> void print(const T &t) { cout << t << ' '; }

template <typename T, typename... Args>
void print(const T &t, const Args &... rest) {
  print(t);
  print(rest...);
}

template <typename T> void println(const T &t) { cout << t << '\n'; }

template <typename T, typename... Args>
void println(const T &t, const Args &... rest) {
  print(t);
  println(rest...);
}

// tourist's modular-arithmetic class
template <typename T> T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T> class Modular {
public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}

  template <typename U> Modular(const U &x) { value = normalize(x); }

  template <typename U> static Type normalize(const U &x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0)
      v += mod();
    return v;
  }

  const Type &operator()() const { return value; }

  template <typename U> explicit operator U() const {
    return static_cast<U>(value);
  }

  constexpr static Type mod() { return T::value; }

  Modular &operator+=(const Modular &other) {
    if ((value += other.value) >= mod())
      value -= mod();
    return *this;
  }

  Modular &operator-=(const Modular &other) {
    if ((value -= other.value) < 0)
      value += mod();
    return *this;
  }

  template <typename U> Modular &operator+=(const U &other) {
    return *this += Modular(other);
  }

  template <typename U> Modular &operator-=(const U &other) {
    return *this -= Modular(other);
  }

  Modular &operator++() { return *this += 1; }

  Modular &operator--() { return *this -= 1; }

  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }

  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }

  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  enable_if_t<is_same<typename Modular<U>::Type, int>::value, Modular> &
  operator*=(const Modular &rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
        d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }

  template <typename U = T>
  enable_if_t<is_same<typename Modular<U>::Type, int64_t>::value, Modular> &
  operator*=(const Modular &rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) *
        rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }

  template <typename U = T>
  enable_if_t<!is_integral<typename Modular<U>::Type>::value, Modular> &
  operator*=(const Modular &rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular &operator/=(const Modular &other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

  template <typename U> friend const Modular<U> &abs(const Modular<U> &v) {
    return v;
  }

  template <typename U>
  friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

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
  U p = b;
  while (p > 0) {
    if (p & 1)
      res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T> bool IsZero(const Modular<T> &number) {
  return number() == 0;
}

template <typename T> string to_string(const Modular<T> &number) {
  return to_string(number());
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
  return stream << number();
}

template <typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
int main() {
#if defined LOCAL && !defined DUIPAI
  ifstream in("in.txt");
  cin.rdbuf(in.rdbuf());
#endif
  // f[i][j] --> f[i + 1][j], f[i+1][j + a[i + 1]]
  int n, s;
  scan(n, s);
  vi a(n);
  scan(a);
  vector<Mint> dp(s + 1);
  Mint ans = 0;
  rng (i, 0, n) {
    down (j, s, a[i] + 1) {
      dp[j] += dp[j - a[i]];
    }
    if (a[i] <= s)
      dp[a[i]] += i + 1;
    ans += dp[s];
  }
  println(ans);
  return 0;
}
