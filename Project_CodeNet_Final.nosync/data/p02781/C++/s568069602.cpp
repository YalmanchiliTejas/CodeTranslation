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
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
//#define fi first
//#define se second
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

i64 ncr(i64 n, i64 r) {
  if (n < r) return 0;
  
  i64 a = 1, b = 1;
  int im = r;
  F0R(i, im) {
    a *= n; b *= r;
    n--; r--;
  }
  return a / b;
}

i64 calc(string N, int K) {

  if (K == 0) return 1;
  if (N.size() == 0) return 0;

  i64 result = 0;

  int n = N.front() - '0';

  // 最上位が0 で、下位は全ての桁が 0～9 をとりうるとき
  if (n > 0) {
    result += ncr(N.size() - 1, K) * pow(9, K);
  }
  //debug(result);

  // 最上位が1以上 n未満（nを最上位の数とするとき）で、
  // 下位は全ての桁が 0～9 をとりうるとき
  if (n > 0) {
    result += (n - 1) * ncr(N.size() - 1, K - 1) * pow(9, K - 1);
    //debug(result);
  }

  // 最上位がn なので、下位の桁のとりうる数が 0～9 のうち一部
  if (n > 0) {
    result += calc(N.substr(1, N.size() - 1), K - 1);
  }
  else {
    result += calc(N.substr(1, N.size() - 1), K);
  }

  return result;
}

i64 calc2(string N, int K) {

  string s = "0";

  i64 result = 0;
  while (true) {

    // count non-zeros
    int nzc = 0;
    for (char c : s) {
      if (c != '0') nzc++;
    }
    if (nzc == K) result++;

    if (s == N) break;

    int idx = s.size() - 1;
    while (true) {
      if (s[idx] != '9') {
        s[idx]++;
        break;
      }
      s[idx] = '0';
      idx--;
      if (idx < 0) {
        s = '1' + s;
        break;
      }
    }
  }

  return result;
}

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

#if 0
  // automatic verify
  F0R(i, 10000) {
    string s = to_string(i);
    FOR(k, 1, 3) {
      if (calc(s, k) != calc2(s, k)) {
        cout << "mismatch" << newl;
        cout << s << ' ' << k << newl;
        cout << calc(s, k) << " != " << calc2(s, k) << newl;
        i = INT32_MAX - 1;
        break;
      }
    }
  }
#endif

  string N;
  int K;
  cin >> N >> K;

  cout << calc(N, K);


}
#endif
