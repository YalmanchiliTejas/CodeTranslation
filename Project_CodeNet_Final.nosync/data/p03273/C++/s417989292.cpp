#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  cin >> a;
  set<int> x, y;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') {
        x.emplace(j);
        y.emplace(i);
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    if (!y.count(i)) continue;
    for (int j = 0; j < w; ++j) {
      if (!x.count(j)) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}

