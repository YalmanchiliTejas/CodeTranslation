/*
 * atcoder/abc130/a.cpp
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

int x;

void input() {
  cin >> x;
}

void solve() {
  if (x==3||x==5|x==7) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}

int main() {
  // cout.precision(15);
  input();
  solve();
  return 0;
}
