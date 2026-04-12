#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i32 = int32_t;
using i64 = int64_t;
constexpr char newl = '\n';

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
//#define F first
//#define S second
#define debug(x) cout << #x << ": " << x << '\n';
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}

#if 1

constexpr int MOD = 1e9 + 7; // 1e9 + 7

template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v% MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getmod() { return MOD; }
  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
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
  constexpr bool operator == (const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream& os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD>& a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string K;
  int D;
  cin >> K;
  cin >> D;

  // dp[i][j] := i桁目までの、各数値が0 ～ 9 の場合の
  // 各桁の数の和 % D = j であるものの数（上にまだ桁があると仮定）
  // 10の累乗について考えるということ
  // 【例】処理中の桁以降が "012345" であれば、[0, 999999] で考える

  // dp2[i][j] := 表現可能な最大値が i 桁目までの入力と同じ場合の
  // 各桁の数の和 % D = j であるものの数（上にもう桁がないと仮定）
  // 10の累乗に収まらない端数（与えられた数列で、0以外で表記されている部分）を考えるということ
  // 【例】処理中の桁以降が "012345" であれば、[1, 12345] で考える

  // 12345 という数列は、10000 + 2345 にわける、みたいな感じ（最終的には1も端数扱いの計算をするけど）

  // 各dpは[i][i-1]まで持てば大丈夫

#if 0
  // 限界化
  K = string(10000, '1');
#endif

  vector<Fp<MOD>> cp(D), cp2(D);
  vector<Fp<MOD>> dp(D), dp2(D);

#if 0
  // [0, n) の整数の桁の数の和を調べる
  F0R(i, 100) {

    int r = 0;
    for (int j = i; j; j /= 10) {
      r += j % 10;
    }
    dp[r % D]++;
  }
  Print(dp);
  return 0;
#endif

  F0R(i, 10) {
    cp[i % D] += 1;
  }
  F0R(i, K.back() - '0') {
    cp2[(i + 1) % D] += 1;
  }

  RF0(i, K.size() - 1) {

    int digit = K[i] - '0';
    //debug(digit);

    // [0, digit * 10^n)
    F0R(j, D) {
      int j2 = j;
      Fp<MOD> a = 0;
      F0R(k, digit) {
        a += cp[j2];
        if (--j2 < 0) j2 += D;
      }
      dp[j] = a;
    }

    // 10^n を digit 倍して 最後に端数を足す
    F0R(j, D) {
      int j2 = j - digit;
      while (j2 < 0) j2 += D;
      dp2[j] = dp[j] + cp2[j2];
    }
    // [0, digit * 10^n) を (0, digit * 10^n] に修正する
    dp2[0] -= 1;
    dp2[digit % D] += 1;

    // [0, digit * 10^n) += [digit * 10^n, 10 * 10^n)
    F0R(j, D) {
      int j2 = j - digit;
      while (j2 < 0) j2 += D;
      Fp<MOD> a = 0;
      FOR(k, digit, 10) {
        a += cp[j2];
        if (--j2 < 0) j2 += D;
      }
      dp[j] += a;
    }

    swap(cp, dp);
    swap(cp2, dp2);
  }

  //Print(cp);
  cout << (cp2[0].val);
}
#endif
