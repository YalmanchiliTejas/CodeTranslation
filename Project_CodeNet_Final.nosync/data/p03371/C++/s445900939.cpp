/*
 * atcoder/abc095_2nd/c.cpp
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

int A, B, AB, X, Y;
void solve() {
  cin >> A >> B >> AB >> X >> Y;
  int d = abs(X-Y);
  int cost = 0;
  if (X > Y) {
    cost += d * min(A, 2 * AB);
    X = Y;
  } else {
    cost += d * min(B, 2 * AB);
    Y = X;
  }
  cost += X * min(A + B, 2 * AB);
  cout << cost << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
