#include <bits/stdc++.h>
using namespace std;

#define range(i, l, r) for (int i = (int)l; i < (int)(r); ++(i))
#define rrange(i, l, r) for (int i = ((int)(r) - 1); i >= (int)l; --(i))

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rwhole(f,x,...) ([&](decltype((x)) whole) { return (f)(rbegin(whole), rend(whole), ## __VA_ARGS__); })(x)

#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

using int32 = int;
using int64 = long long;

const int mod     = 1e9 + 7;
const int32 inf   = 1001001001;
const int64 infll = 1001001001001001001ll;

const int dx[] = {0, -1, 1, 0, -1, 1, -1, 1}, dy[] = {-1, 0, 0, 1, -1, -1, 1, 1};
const string YES = "YES", NO = "NO", Yes = "Yes", No = "No", yes = "yes", no = "no";

struct IoSetup { IoSetup(){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(16); cerr << fixed << setprecision(16); } } iosetup;

template <typename T = int64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; } 
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << p.fs << " " << p.sc; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.fs >> p.sc; return is; }

template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template < int mod >
class mod_int {

  int_fast32_t num_;

public:
  mod_int() : num_(0) {}
  mod_int(int_fast64_t num_) : num_(num_ >= 0 ? num_ % mod : (mod + num_ % mod) % mod) {}

  inline int_fast32_t num() const { return num_; }
  operator int_fast32_t() { return num_; }

  inline mod_int inverse() const {
    int_fast32_t a = num_, b = mod, u = 1, v = 0, t;
    while (b) { t = a / b; std::swap(a -= t * b, b); std::swap(u -= t * v, v); }
    return mod_int(u);
  }
 
  mod_int operator~() const { return inverse(); }
  mod_int operator+() const { return *this; }
  mod_int operator-() const { return mod_int(-num_); }

  mod_int &operator+=(const mod_int &rhs) { if ((num_ += rhs.num_) >= mod) num_ -= mod; return *this; }
  mod_int &operator-=(const mod_int &rhs) { if ((num_ -= rhs.num_) <  0)   num_ += mod; return *this; }
  mod_int &operator*=(const mod_int &rhs) { num_ = int_fast64_t(num_) * rhs.num_ % mod; return *this; }
  mod_int &operator/=(const mod_int &rhs) { return *this *= rhs.inverse(); }

  mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }
  mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }
  mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }
  mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }

  bool operator==(const mod_int &rhs) const { return num_ == rhs.num_; }
  bool operator!=(const mod_int &rhs) const { return num_ != rhs.num_; }

  friend std::ostream &operator<<(std::ostream &os, const mod_int &rhs) {
    return os << rhs.num_;
  }

  friend std::istream &operator>>(std::istream &is, mod_int &rhs) {
    int_fast64_t num; is >> num; rhs = mod_int< mod >(num);
    return is;
  }

  friend mod_int pow(mod_int lhs, int_fast64_t rhs) {
    mod_int res(1);
    for (; rhs; rhs >>= 1) {
      if (rhs & 1) res *= lhs;
      lhs *= lhs;
    }
    return res;
  }
};

template< int mod >
class mod_combinatorics {

  std::size_t size_;
  std::vector< mod_int< mod > > fact_, finv_, invs_;

public:
  mod_combinatorics(std::size_t size) : size_(size + 1), fact_(size_), finv_(size_), invs_(size_) {
    fact_[0] = 1;
    for (int i = 1; i < size_; ++i) fact_[i] = fact_[i - 1] * mod_int< mod >(i);

    finv_.back() = fact_.back().inverse();
    for (int i = int_fast32_t(size_) - 2; i >= 0; --i) finv_[i] = finv_[i + 1] * mod_int< mod >(i + 1);
    for (int i = 0; i < size; ++i) invs_[i] = finv_[i] * fact_[i - 1];
  }

  inline void boundary_check(int n) const {
    if (size_ < n) {
      std::cerr << "boudary error" << std::endl;
    }
  }

  // k!
  mod_int< mod > fact(int k) const {
    boundary_check(k);
    return fact_[k];
  }

  // P(n, k)
  mod_int< mod > permutation(int n, int k) const {
    boundary_check(n);
    if (k < 0 || n < k) return mod_int< mod >(0);
    return fact_[n] * finv_[n - k];
  }

  // C(n, k)
  mod_int< mod > combination(int n, int k) const {
    boundary_check(n);
    if (k < 0 || n < k) return mod_int< mod >(0);
    return fact_[n] * finv_[k] * finv_[n - k];
  }

  // H(n, k)
  mod_int< mod > multichoose(int n, int k) const {
    boundary_check(n + k - 1);
    if (n < 0 || k < 0) return mod_int< mod >(0);
    if (k == 0) return mod_int< mod >(0);
    return fact_[n + k - 1] * finv_[k] * finv_[n - 1];
  }
};

void solver() {
  int N = input(), M = input(), K = input();
  mod_int< mod > n(N), m(M);

  mod_combinatorics< mod > mc(N * M);

  auto f = [&](mod_int< mod > n, mod_int< mod > m) {
    mod_int< mod > res;
    range(d, 1, n) {
      res += (n - mod_int< mod >(d)) * m * m * mod_int< mod >(d);
    }

    return res;
  };

  cout << (f(n, m) + f(m, n)) * mc.combination(M * N - 2, K - 2) << endl;
}

signed main(int argc, char *argv[]) {
  solver();
}
