/*
 * atcoder/abc95/c.cpp
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
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

/*
 * i: XとYが異なる場合) XとYが等しくなるまで買い、等しい場合に帰着させる.
 * ii: XとYが等しい場合）min(AとBの値段, ABの値段)
 *
 * iの補足) XとYの差分をdとするとABの場合にはd*2枚必要. AまたはBの場合にはd枚必要.
 */
int A, B, AB, X, Y;
void solve() {
  cin >> A >> B >> AB >> X >> Y;
  int cost = 0;
  if (X != Y) {
    int d = abs(X-Y);
    cost += min(d*2*AB, X > Y ? d * A : d * B);
    X=min(X,Y);
  }

  cost += min(X*A+X*B, X*2*AB);
  cout << cost << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
