#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

// const int N = 110;
// typedef array<int, N> bigint;

// bigint operator +(const bigint& a, const bigint& b) {
//   bigint ret;
//   int carry = 0;
//   for (int i = 0; i < N; ++i) {
//     int cur = carry + a[i] + b[i];
//     ret[i] = cur % 10;
//     carry = cur / 10;
//   }
//   return ret;
// }

// bigint operator *(const bigint& a, const bigint& b) {
//   bigint ret;
//   for (int i = 0; i < N; ++i) {
//     for (int j = 0; j < N; ++j) {
//       ret[i + j] += a[i] * b[j];
//     }
//   }
//   int carry = 0;
//   for (int i = 0; i < N; ++i) {
//     int cur = ret[i] + carry;
//     ret[i] = cur % 10;
//     carry = cur / 10;
//   }
//   return ret;
// }

// bigint operator *(const bigint& a, int b) {
//   int carry = 0;
//   bigint ret;
//   for (int i = 0; i < N; ++i) {
//     int cur = a[i] * b + carry;
//     ret[i] = cur % 10;
//     carry = cur / 10;
//   }
//   return ret;
// }

// bigint C[N][N];

const int N = 110;
string s;
int n, m;
int64 dp[N][N][2];

int64 solve(int pos, int cnt, bool tight) {
  if (cnt > m) return 0;
  if (pos == n) return cnt == m ? 1 : 0;
  int64& ret = dp[pos][cnt][tight];
  if (ret >= 0) return ret;
  ret = 0;
  for (int i = 0; i < 10; ++i) {
    if (tight && i > s[pos] - '0') break;
    bool nxt_tight = tight && (i == s[pos] - '0');
    int nxt_cnt = cnt + (i > 0);
    ret += solve(pos + 1, nxt_cnt, nxt_tight);
  }
  return ret;
}

int main() {
  cin >> s >> m;
  n = s.size();
  memset(dp, 255, sizeof(dp));
  int64 ret = solve(0, 0, 1);
  cout << ret << endl;
  return 0;
}
