#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 62;
constexpr double EPS = 1e-9;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pa) {
  return os << "(" << pa.first << ", " << pa.second << ")";
}

template<typename Tuple, size_t N>
struct TuplePrinter {
  static void print(const Tuple &t) {
    TuplePrinter<Tuple, N-1>::print(t);
    cout << ", " << get<N-1>(t);
  }
};

template<typename Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(const Tuple &t) {
    cout << get<0>(t);
  }
};

template<typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &tup) {
  os << "(";
  TuplePrinter<decltype(tup), sizeof...(T)>::print(tup);
  return os << ")";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &se) {
  os << "{";
  for (auto it = se.begin(); it != se.end(); ++it) {
    if (it != se.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &ma) {
  os << "{";
  for (auto it = ma.begin(); it != ma.end(); ++it) {
    if (it != ma.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "}";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

/**
 * @brief constexpr Modint data structure
 * @note support + - * / inv pow == != iostream
 */
template<long long MOD = 1000000007>
struct Mint {
private:
  long long val;

public:
  constexpr Mint(const long long x = 0) noexcept : val(x < 0 ? x % MOD + MOD : x >= MOD ? x % MOD : x) {}
  constexpr Mint &operator+=(const Mint rhs) noexcept {
    if ((val += rhs.val) >= MOD) val -= MOD;
    return *this;
  }
  constexpr Mint &operator-=(const Mint rhs) noexcept {
    if ((val -= rhs.val) < 0) val += MOD;
    return *this;
  }
  constexpr Mint &operator*=(const Mint rhs) noexcept {
    val = val * rhs.val % MOD;
    return *this;
  }
  constexpr Mint &operator/=(Mint rhs) noexcept {
    val = val * rhs.inv().val % MOD;
    return *this;
  }
  constexpr Mint operator+(const Mint& rhs) const noexcept { return Mint(*this) += rhs; }
  constexpr Mint operator-(const Mint& rhs) const noexcept { return Mint(*this) -= rhs; }
  constexpr Mint operator*(const Mint& rhs) const noexcept { return Mint(*this) *= rhs; }
  constexpr Mint operator/(const Mint& rhs) const noexcept { return Mint(*this) /= rhs; }
  constexpr Mint inv() const noexcept { return pow(MOD-2); }
  constexpr Mint pow(long long n) const noexcept {
    Mint ret(1), mul(val);
    while (n) {
      if (n % 2) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  constexpr bool operator==(const Mint& rhs) const noexcept { return val == rhs.val; }
  constexpr bool operator!=(const Mint& rhs) const noexcept { return val != rhs.val; }
  friend ostream &operator<<(ostream &os, const Mint<MOD> &x) { return os << x.val; }
  friend istream &operator>>(istream &is, Mint<MOD> &x) {
    long long t;
    is >> t;
    x.val = t % MOD;
    return is;
  }
};


int main() {
  int n; cin>>n;
  vector<Mint<>> a(n);
  rep(i, n) cin>>a[i];
  vector<Mint<>> acc(n, 0);
  acc[0] = a[0];
  REP(i, 1, n) acc[i] = acc[i-1] + a[i];

  Mint<> ans = 0;
  rep(i, n) ans += a[i] * (acc[n-1] - acc[i]);
  print(ans);

  return 0;
}