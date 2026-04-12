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

const long long MOD_CONST = 1000000007;
long long mul_mod(long long a, long long b, const long long MOD) {
  return b ? (mul_mod(a * 2, b / 2, MOD) + (b & 1 ? a : 0)) % MOD : 0;
}

long long bpow_mod(long long a, long long b, const long long MOD) {
  return (b ? bpow_mod(a * a % MOD, b / 2, MOD) * (b & 1 ? a : 1) : 1) % MOD;
}

long long inv_mod(long long a, const long long MOD) {
  return bpow_mod(a, MOD - 2, MOD);
}
template <long long param = MOD_CONST, bool fast = false>
class mint {
 private:
  using Z = int;
  using N = unsigned int;
  using ZZ = long long;
  using NN = unsigned long long;
  struct {
  } constexpr static exact{};
  // Using Z deliberately to avoid Z -> N promotion.
  template <class Ret = ZZ&>
  static auto modulo() -> std::enable_if_t<(param <= 0), Ret> {
    static ZZ mod = 0;
    return mod;
  }
  template <class Ret = const ZZ>
  static auto mod() -> std::enable_if_t<(param <= 0), Ret> {
    return modulo();
  }
  template <class Ret = const ZZ>
  static constexpr auto mod() -> std::enable_if_t<(param > 0), Ret> {
    return param;
  }

 public:
  template <class Arg = ZZ>
  static void set_modulo(const std::enable_if_t<(param <= 0), Arg> mod) {
    modulo() = mod;
  }
  long long v;

  constexpr mint() : v(0) {}

  constexpr mint(long long v)
      : v(fast ? (v)
               : (v < 0 ? (v % mod() + mod()) % mod()
                        : (v >= mod() ? v % mod() : v))) {}
  constexpr long long get_mod() { return mod(); }
  long long get_val() { return v; }
  void take_mod() { v %= mod(); }
};
template <long long param, bool fast>
ostream& operator<<(ostream& os, mint<param, fast>& x) {
  return os << (x.v % x.get_mod() + x.get_mod()) % x.get_mod();
}

template <long long param, bool fast, bool fast2>
bool operator==(mint<param, fast>& a, mint<param, fast2> b) {
  return a.v == b.v;
}
template <long long param, bool fast, bool fast2>
mint<param, fast>& operator+=(mint<param, fast>& a, mint<param, fast2> b) {
  return a = a.v + b.v;
}
template <long long param>
mint<param>& operator-=(mint<param>& a, mint<param> b) {
  return a = a.v - b.v;
}
template <long long param>
mint<param>& operator*=(mint<param>& a, mint<param> b) {
  return a = a.v * b.v;
}
template <long long param>
mint<param>& operator/=(mint<param>& a, mint<param> b) {
  return a = a.v * inv_mod(b.v, a.get_mod());
}
template <long long param, bool fast, bool fast2>
mint<param, fast> operator+(mint<param, fast> a, mint<param, fast2> b) {
  return a += b;
}
template <long long param>
mint<param> operator-(mint<param> a, mint<param> b) {
  return a -= b;
}
template <long long param>
mint<param> operator*(mint<param> a, mint<param> b) {
  return a *= b;
}
template <long long param>
mint<param> operator/(mint<param> a, mint<param> b) {
  return a /= b;
}
template <long long param, bool fast>
mint<param, fast>& operator+=(mint<param, fast>& a, long long b) {
  return a = a.v + b;
}
template <long long param>
mint<param>& operator-=(mint<param>& a, long long b) {
  return a = a.v - b;
}
template <long long param>
mint<param>& operator*=(mint<param>& a, long long b) {
  return a = a.v * b;
}
template <long long param>
mint<param>& operator/=(mint<param>& a, long long b) {
  return a = a.v * inv_mod(b, a.get_mod());
}
template <long long param, bool fast>
mint<param, fast> operator+(mint<param> a, long long b) {
  return a += b;
}
template <long long param>
mint<param> operator-(mint<param> a, long long b) {
  return a -= b;
}
template <long long param>
mint<param> operator*(mint<param> a, long long b) {
  return a *= b;
}
template <long long param>
mint<param> operator/(mint<param> a, long long b) {
  return a /= b;
}

void special(int N) {
  vector<mint<>> vals = {mint<>(1), mint<>(1)};
  for (int i = 0; i < N; i++) {
    int sz = vals.size();
    vals.push_back(vals[sz - 1] + vals[sz - 2]);
  }
  mint<> ans = vals[N] + vals[N - 2];
  cout << ans << endl;
}

int con(string& S, char t) {
  int ans = 1000000;
  int cur = 0;
  int first = 0;
  if (S[0] != t) first++;
  for (auto c : S) {
    if (c == t)
      cur++;
    else {
      if (first == 0) {
        first++;
        ans = cur;
      }

      if (cur % 2 == 1) ans = min(ans, cur);
      cur = 0;
    }
  }
  // chmin(ans, cur);
  return ans;
}

mint<> calcDP(int N, int conB, int conR) {
  vector<mint<>> dpR(N + 2, mint<>(0));
  vector<mint<>> dpB(N + 2, mint<>(0));
  vector<mint<>> sumR(N + 2, mint<>(0));
  vector<mint<>> sumB(N + 2, mint<>(0));
  dpR[1] = 1;
  sumR[1] = 1;
  for (int i = 2; i <= N + 1; i++) {
    if (i % 2 == 1) {
      dpR[i] = sumB[i - 1] - sumB[max(0, i - conR - 1)];

    } else
      dpB[i] = sumR[i - 1] - sumR[max(0, i - conB - 1)];
    sumB[i] = sumB[i - 1] + dpB[i];
    sumR[i] = sumR[i - 1] + dpR[i];
  }
  mint<> ans = 0;
  for (int i = 0; i < min(N, conB + 1); i++) {
    ans += sumR[N - i] - sumR[max(0, N - conB - 2)];
  }
  return ans;
}

void solve(long long N, long long M, std::string S) {
  int cntB = 0;

  int conR = con(S, 'R');
  int conB = con(S, 'B');
  for (int i = 0; i < M; i++) {
    if (S[i] == 'B') cntB++;
  }
  if (cntB == M || cntB == 0) {
    special(N);
    return;
  }
  if (N % 2 == 1) {
    cout << 0 << endl;
    return;
  }
  if (S[0] == 'R') swap(conR, conB);
  conR = 1;
  if (conB % 2 == 0) conB++;
  // if (conR % 2 == 0) conR--;

  mint<> ans = calcDP(N, conB, conR);
  cout << ans << endl;
}

int main() {
  cout << setprecision(10);
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::string S;
  std::cin >> S;
  solve(N, M, S);
  return 0;
}
