#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

// chmax, chmin
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
function<T(T, T)> op_max = [](T a, T b) -> T { return max(a, b); };
template <typename T>
function<T(T, T)> op_min = [](T a, T b) -> T { return min(a, b); };

template <typename T>
function<T(T, T)> op_sum = [](T a, T b) -> T { return a + b; };

namespace detail {
template <typename T, std::size_t NDIMS>
struct vector_builder {
  using type = std::vector<typename vector_builder<T, NDIMS - 1>::type>;

  static type make(std::vector<std::size_t> dims, const T& v = {}) {
    const auto vec = std::vector<T>(dims.empty() ? 0 : dims.back(), v);
    if (!dims.empty()) dims.pop_back();
    return vector_builder<std::vector<T>, NDIMS - 1>::make(dims, vec);
  }
};

template <typename T>
struct vector_builder<T, 1> {
  using type = std::vector<T>;

  static type make(std::vector<std::size_t> dims, const T& v = {}) {
    return type(dims.empty() ? 0 : dims.back(), v);
  }
};
}  // namespace detail

template <typename T, typename... SIZE_T>
auto exvector(const T& v, SIZE_T... dims) {
  static_assert(sizeof...(dims) != 0, "invalid dimension");
  std::vector<std::size_t> vec_dims{dims...};
  return detail::vector_builder<T, sizeof...(dims)>::make(vec_dims, v);
}

using namespace std;
//********************  dumps ************************//

template <typename T>
void dump(const T& data, vector<int>& iter) {
  cout << data << " ";
}
template <typename T>
void dump(const vector<T>& data, vector<int>& iter) {
  for (auto elem : data) dump(elem, iter);
  cout << endl;
}

template <typename T>
void dump(const vector<vector<T>>& data, vector<int>& iter) {
  for (auto elem : iter) {
    cout << "[" << elem << "]";
  }
  cout << endl;
  for (int i = 0; i < data.size(); i++) {
    iter.push_back(i);
    dump(data[i], iter);
    iter.pop_back();
  }
  cout << endl;
}

template <typename T>
void dump(const vector<T>& data, int dummy) {
  for (int i = 0; i < data.size(); i++) {
    cout << "[" << i << "] " << data[i] << endl;
  }
}
template <typename T>
void dump(const T& data) {  // T : data, U = base type val.
  vector<int> iter;
  dump(data, iter);
}
///////////////////////////////////////////////

const long long MOD = 1000000007;

long long mul(long long a, long long b, const long long MOD) {
  return b ? (mul(a * 2, b / 2, MOD) + (b & 1 ? a : 0)) % MOD : 0;
}

long long bpow(long long a, long long b, const long long MOD) {
  return (b ? bpow(a * a % MOD, b / 2, MOD) * (b & 1 ? a : 1) : 1) % MOD;
}

long long inv(long long a, const long long MOD) {
  return bpow(a, MOD - 2, MOD);
}

vector<long long> MODS = {1000000007};
template <int kind = 0>
class mint {
 public:
  long long v;

  mint() : v(0) {}
  mint(long long v) : v((v % MODS[kind] + MODS[kind]) % MODS[kind]) {}
  long long get_mod() { return MODS[kind]; }
  long long get_val() { return v; }
};

template <int kind>
ostream& operator<<(ostream& os, const mint<kind>& x) {
  return os << x.v;
}

template <int kind>
mint<kind>& operator+=(mint<kind>& a, mint<kind> b) {
  return a = a.v + b.v;
}
template <int kind>
mint<kind>& operator-=(mint<kind>& a, mint<kind> b) {
  return a = a.v - b.v;
}
template <int kind>
mint<kind>& operator*=(mint<kind>& a, mint<kind> b) {
  return a = a.v * b.v;
}
template <int kind>
mint<kind>& operator/=(mint<kind>& a, mint<kind> b) {
  return a = a.v * inv(b.v, a.get_mod());
}
template <int kind>
mint<kind> operator+(mint<kind> a, mint<kind> b) {
  return a += b;
}
template <int kind>
mint<kind> operator-(mint<kind> a, mint<kind> b) {
  return a -= b;
}
template <int kind>
mint<kind> operator*(mint<kind> a, mint<kind> b) {
  return a *= b;
}
template <int kind>
mint<kind> operator/(mint<kind> a, mint<kind> b) {
  return a /= b;
}
template <int kind>
mint<kind>& operator+=(mint<kind>& a, long long b) {
  return a = a.v + b;
}
template <int kind>
mint<kind>& operator-=(mint<kind>& a, long long b) {
  return a = a.v - b;
}
template <int kind>
mint<kind>& operator*=(mint<kind>& a, long long b) {
  return a = a.v * b;
}
template <int kind>
mint<kind>& operator/=(mint<kind>& a, long long b) {
  return a = a.v * inv(b, a.get_mod());
}
template <int kind>
mint<kind> operator+(mint<kind> a, long long b) {
  return a += b;
}
template <int kind>
mint<kind> operator-(mint<kind> a, long long b) {
  return a -= b;
}
template <int kind>
mint<kind> operator*(mint<kind> a, long long b) {
  return a *= b;
}
template <int kind>
mint<kind> operator/(mint<kind> a, long long b) {
  return a /= b;
}

vector<mint<>> kaijo;
mint<> comb(int n, int k) { return kaijo[n] / kaijo[k] / kaijo[n - k]; }
vector<mint<>> powpow2;
vector<mint<>> pow2;
vector<vector<mint<>>> stirling;

void init() {
  int N = 3100;
  int M = N * N;
  kaijo = vector<mint<>>(N, mint<>(0));
  kaijo[0] = 1;
  for (int i = 1; i < N; i++) {
    kaijo[i] = kaijo[i - 1] * i;
  }

  mint<> cur = 2;
  for (int i = 0; i < N; i++) {
    powpow2.push_back(cur);
    cur *= cur;
  }
  cur = 1;
  for (int i = 0; i < N; i++) {
    pow2.push_back(cur);
    cur *= 2;
  }
  stirling = exvector(mint<>(0), N, N);
  for (LL i = 0; i < N; i++)
    for (LL j = 1; j <= i; j++) {
      if (j == 1 || j == i)
        stirling[i][j] = 1;
      else {
        stirling[i][j] = stirling[i - 1][j - 1] + stirling[i - 1][j] * j;
      }
    }
}

int main() {
  int N, M;
  cin >> N >> M;
  MODS[0] = M;
  init();

  mint<> ans = 0;
  for (int k = 0; k <= N; k++) {
    mint<> res = 0;
    mint<> t = 1;
    for (int p = 0; p <= k; p++) {
      res += stirling[k + 1][p + 1] * t;
      t *= pow2[N - k];
    }
    res *= powpow2[N - k];
    if (k % 2 == 1) res *= -1;
    ans += res * comb(N, k);
  }
  cout << ans << endl;
  return 0;
}
