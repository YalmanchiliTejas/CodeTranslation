#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << '\n';
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}

#if 1

constexpr int MOD = 1e9 + 7;
template<int MOD>
struct Modint {
  long long val;
  constexpr Modint(long long v = 0) noexcept : val(v% MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Modint operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr Modint operator + (const Modint& r) const noexcept { return Modint(*this) += r; }
  constexpr Modint operator - (const Modint& r) const noexcept { return Modint(*this) -= r; }
  constexpr Modint operator * (const Modint& r) const noexcept { return Modint(*this) *= r; }
  constexpr Modint& operator += (const Modint& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Modint& operator -= (const Modint& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Modint& operator *= (const Modint& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr bool operator == (const Modint& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Modint& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream& os, const Modint<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr istream& operator >> (istream& is, Modint<MOD>& x) noexcept {
    return is >> x.val;
  }

  constexpr Modint<MOD> pow(long long n) const noexcept {
    if (!n) return 1;
    auto t = pow(n >> 1);
    t *= t;
    if (n & 1) t *= *this;
    return t;
  }
  friend constexpr Modint<MOD> modpow(const Modint<MOD>& a, long long n) noexcept {
    return a.pow(n);
  }

  friend constexpr Modint<MOD> Ncr(Modint<MOD> a, int n) {
    Modint<MOD> p = 1, q = 1;

    while (n > 0) {
      p *= a;
      a -= 1;
      q *= n--;
    }

    return p / q;
  }

  // for prime mod
  constexpr Modint inv() const { return pow(MOD - 2); }
  constexpr Modint& operator /= (const Modint& r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Modint operator / (const Modint& r) const noexcept { return Modint(*this) /= r; }
};
using mint = Modint<MOD>;

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  i64 K, nm;
  cin >> N >> M >> K;
  nm = (i64)N * M;
  //mint pc = Ncr(mint(nm), K); // 全パターン数
  mint c2 = Ncr(mint(nm - 2), K - 2); // 特定の1ペアが含まれるパターン数

  // N*M全マスに配置したときのコストを計算する
  mint yc = 0;
  FOR(i, 1, N) {
    yc += (i64)(N - i) * i;
  }
  yc *= (i64)M * M;
  mint xc = 0;
  FOR(i, 1, M) {
    xc += (i64)(M - i) * i;
  }
  xc *= (i64)N * N;
  //debug(xc);
  //debug(yc);

  mint result = (xc + yc) * c2;
  cout << result;
}
#endif
