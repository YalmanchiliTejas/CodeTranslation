/*
 * atcoder/abc134/e.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
#include <set>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> ostream & operator << (ostream & out, vector<T> const & v) {
  for (auto &&a: v) out << a << " "; out << endl; return out;
}
template <class T> void dump(T &a) { cout << a << endl; }
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

int N;
vector<int> A;
void solve() {
  cin >> N;
  A.resize(N);
  multiset<int> S;

  loop(n,0,N) cin >> A[n];

  for (auto&&a: A) {
    auto iter = S.lower_bound(a);
    if (iter != S.begin()) S.erase(--iter);
    S.insert(a);
  }
  cout << S.size() << endl;

}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
