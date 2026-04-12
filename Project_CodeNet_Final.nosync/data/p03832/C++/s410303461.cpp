#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

template<int M, bool IsPrime = false>
class Modulo {
  using ll = long long;
  int n;
  static enable_if_t<IsPrime, ll> inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  Modulo (ll m) {
    if (m >= M) m %= M;
    else if (m < 0) m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
  enable_if_t<IsPrime, Modulo> operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
};

template<int M> Modulo<M, true> fact(int n, bool sw = true) {
  static vector<Modulo<M, true>> v1 = {1}, v2 = {1};
  if (n >= (int)v1.size()) {
    const int from = v1.size(), to = n + 1024;
    v1.reserve(to);
    v2.reserve(to);
    for (int i = from; i < to; ++i) {
      v1.push_back(v1.back() * Modulo<M, true>(i));
      v2.push_back(v2.back() / Modulo<M, true>(i));
    }
  }
  return sw ? v1[n] : v2[n];
}

template<int M> Modulo<M, true> comb(int a, int b) {
  if (b < 0 || b > a) return fact<M>(0);
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

const int mod = 1000000007;
using Mod = Modulo<mod, true>;

int b, c, d;

Mod memo[1024][1024];
bool visited[1024][1024];

Mod dp(int N, int a) {
  if (visited[N][a]) return memo[N][a];
  if (N < 0) return 0;
  if (a > b) return Mod(N == 0);
  Mod res = dp(N, a + 1);
  for (int i = c; i <= d && i * a <= N; ++i) {
    res += comb<mod>(N, i * a) * fact<mod>(i * a) * (fact<mod>(a, false)^i)
      * fact<mod>(i, false) * dp(N - i * a, a + 1);
  }
  // cout << N << " " << a << " " << int(res) << endl;
  visited[N][a] = true;
  return memo[N][a] = res;
}

void solve(ll N, ll A, ll B, ll C, ll D) {
  b = B; c = C; d = D;
  cout << int(dp(int(N), int(A))) << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll D;
	ll A;
	ll B;
	ll N;
	ll C;
	scanf("%lld", &N);
	scanf("%lld", &A);
	scanf("%lld", &B);
	scanf("%lld", &C);
	scanf("%lld", &D);
	solve(N, A, B, C, D);
	return 0;
}
