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

using vi = vector<int>;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
#define fi first
#define se second
#define show(x) cout << #x << " = " << x << '\n';
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define YesNo {cout<<"Yes";}else{cout<<"No";}
#define v(T) vector<T>

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}
template<class T> bool lcmp(const pair<T, T>& l, const pair<T, T>& r) {
  return l.first < r.first;
}
template<class T> istream& operator>>(istream& i, v(T)& v) {
  F0R(j, sz(v)) i >> v[j];
  return i;
}

#if 1


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  i64 X;
  cin >> N >> X;

  vector<i64> as(51), bs(51);
  as[0] = bs[0] = 1;

  F0R(i, 50) {
    as[i + 1] = as[i] * 2 + 1;
    bs[i + 1] = bs[i] * 2 + 3;
  }

  i64 r = 0;
  auto eat = [&](auto eat, int level)->void {
    if (!level) {
      if (X) {
        r++;
        X--;
      }
      return;
    }

    X--;
    if (X <= 0) return;
    if (X < bs[level - 1]) {
      eat(eat, level - 1);
      return;
    }
    X -= bs[level - 1];
    r += as[level - 1];
    if (X <= 0) return;
    X--; r++;
    if (X <= 0) return;
    if (X < bs[level - 1]) {
      eat(eat, level - 1);
      return;
    }
    X -= bs[level - 1];
    r += as[level - 1];
    X--;
  };
  eat(eat, N);
  cout << r;
}
#endif
