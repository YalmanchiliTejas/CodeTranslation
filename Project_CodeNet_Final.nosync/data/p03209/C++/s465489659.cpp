/*
 * atcoder/abc115_3rd/d.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> ostream & operator << (ostream & out, vector<T> const & v) {
  for (auto &&a: v) out << a << " "; out << endl; return out;
}
template <class T> void dump(T &a) { cout << a << endl; }
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

/*
 * L0     p   p       p   p
 * L1   b   p   b   b   p   b
 * L2 b           p           b
 */
int N; ll X;
ll rec(int n, ll x) {
  if (n==0) return 1;
  if (x<=1) return 0;
  ll all = (1LL<<(n+1)) - 3; // １つ低レベルの全パーツ数
  ll p   = (1LL<<n) - 1;     //               p数

  if (x <= all + 1) return rec(n-1, x-1);
  if (x == all + 2) return 1 + p;
  if (x <= 2 * all + 2) return 1 + p + rec(n-1, x - all - 2);
  return 1 + 2 * p;
}

void solve() {
  cin >> N >> X;
  cout << rec(N, X) << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
