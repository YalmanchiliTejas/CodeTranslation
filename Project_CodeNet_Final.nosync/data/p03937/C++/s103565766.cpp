#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <bitset>
#include <cstdint>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

i64 h, w;
vector<string> a;
int main() {
  cin >> h >> w;
  read_n(a, h);

  i64 i = 0, j = 0;
  while (true) {
    a[i][j] = '.';
    if (i < h - 1 && a[i + 1][j] == '#') ++i;
    else if (j < w - 1 && a[i][j + 1] == '#') ++j;
    else break;
  }
  for (i64 i = 0; i < h; ++i) {
    for (i64 j = 0; j < w; ++j) {
      if (a[i][j] == '#') {
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  cout << "Possible\n";
  return 0;
}
