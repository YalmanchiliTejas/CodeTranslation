#include <bits/stdc++.h>

template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))>>
    : std::true_type {};

template <typename T, typename = void>
struct is_pair : std::false_type {};
template <typename T>
struct is_pair<T, std::void_t<decltype(std::declval<T>().first),
                              decltype(std::declval<T>().second)>>
    : std::true_type {};

template <typename T>
void debug(const T& v) {
  if constexpr (is_pair<T>::value) {
    std::cerr << "{";
    debug(v.first);
    std::cerr << ", ";
    debug(v.second);
    std::cerr << "}";
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    std::cerr << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
      if (it != v.begin()) std::cerr << ", ";
      debug(*it);
    }
    std::cerr << "}";
  } else {
    std::cerr << v;
  }
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  debug(value);
  std::cerr << ", ";
  debug(args...);
}
#if DEBUG
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);
#define ints(...) rd(int, __VA_ARGS__);
#define strings(...) rd(string, __VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  if constexpr (std::is_same<T, bool>::value) {
    std::cout << (value ? "Yes" : "No");
  } else {
    std::cout << value;
  }
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  write_to_cout(value);
  std::cout << ' ';
  write_to_cout(args...);
}
#define wt(...)                 \
  do {                          \
    write_to_cout(__VA_ARGS__); \
    cout << '\n';               \
  } while (0)

#define all(x) (x).begin(), (x).end()

#define rep_dispatch(_1, _2, _3, name, ...) name
#define rep3(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(_loop_variable_, n)
#define rep(...) rep_dispatch(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T, typename U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
bool chmin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
int sz(const T& v) {
  return v.size();
}

#include <boost/hana/functional/fix.hpp>
const auto& Fix = boost::hana::fix;

using ll = long long;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

#define BIN_OPS(F) F(+) F(-) F(*) F(/)
#define CMP_OPS(F) F(!=) F(<) F(<=) F(==) F(>) F(>=)

template <int Mod = 1000000007>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(long long n) : n_(n % Mod) {
    if (n_ < 0) {
      // In C++, (-n)%m == -(n%m).
      n_ += Mod;
    }
  }
  ModInt& operator+=(const ModInt& m) {
    n_ += m.n_;
    if (n_ >= Mod) {
      n_ -= Mod;
    }
    return *this;
  }
  ModInt& operator++() { return (*this) += 1; }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt& operator--() { return (*this) -= 1; }
  ModInt& operator*=(const ModInt& m) {
    n_ *= m.n_;
    n_ %= Mod;
    return *this;
  }
  ModInt& operator/=(const ModInt& m) {
    *this *= m.Inv();
    return *this;
  }
#define DEFINE(op) \
  ModInt operator op(const ModInt& m) const { return ModInt(*this) op## = m; }
  BIN_OPS(DEFINE)
#undef DEFINE
#define DEFINE(op) \
  bool operator op(const ModInt& m) const { return n_ op m.n_; }
  CMP_OPS(DEFINE)
#undef DEFINE
  ModInt operator-() const { return ModInt(-n_); }
  ModInt Pow(int n) const {
    if (n < 0) {
      return Inv().Pow(-n);
    }
    // a * b ^ n = answer.
    ModInt a = 1, b = *this;
    while (n != 0) {
      if (n & 1) {
        a *= b;
      }
      n /= 2;
      b *= b;
    }
    return a;
  }
  ModInt Inv() const {
    // Compute the inverse based on Fermat's little theorem. Note that this only
    // works when n_ and Mod are relatively prime. The theorem says that
    // n_^(Mod-1) = 1 (mod Mod). So we can compute n_^(Mod-2).
    return Pow(Mod - 2);
  }
  long long value() const { return n_; }

  static ModInt Fact(int n) {
    for (int i = fact_.size(); i <= n; ++i) {
      fact_.push_back(i == 0 ? 1 : fact_.back() * i);
    }
    return fact_[n];
  }
  static ModInt Comb(int n, int k) { return Perm(n, k) / Fact(k); }
  static ModInt CombSlow(int n, int k) { return PermSlow(n, k) / Fact(k); }
  static ModInt Perm(int n, int k) {
#if DEBUG
    assert(n <= 1000000 &&
           "n is too large. If k is small, consider using PermSlow.");
#endif
    return Fact(n) / Fact(n - k);
  }
  static ModInt PermSlow(int n, int k) {
    ModInt p = 1;
    for (int i = 0; i < k; ++i) {
      p *= (n - i);
    }
    return p;
  }

 private:
  long long n_;
  static std::vector<ModInt> fact_;
};

template <int Mod>
std::vector<ModInt<Mod>> ModInt<Mod>::fact_;

#define DEFINE(op)                                            \
  template <int Mod, typename T>                              \
  ModInt<Mod> operator op(const T& t, const ModInt<Mod>& m) { \
    return ModInt<Mod>(t) op m;                               \
  }
BIN_OPS(DEFINE)
CMP_OPS(DEFINE)
#undef DEFINE

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  mint sum = accumulate(all(a), mint(0));
  mint ans = 0;
  rep(i, n) ans += (sum - a[i]) * a[i];
  wt(ans / 2);
}
