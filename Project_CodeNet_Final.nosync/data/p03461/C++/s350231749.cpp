#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int a, b; cin >> a >> b;
  VV<> d; assign(d, a + 1, b + 1, 0);
  for (int x = 1; x <= a; ++x) for (int y = 1; y <= b; ++y) cin >> d[x][y];
  VV<> c; assign(c, 101, 101, 0);
  for (int i = 0; i <= 100; ++i) for (int j = 0; j <= 100; ++j) {
    for (int x = 1; x <= a; ++x) for (int y = 1; y <= b; ++y) {
      c[i][j] = max(c[i][j], d[x][y] - i * x - j * y);
    }
  }
  for (int x = 1; x <= a; ++x) for (int y = 1; y <= b; ++y) {
    int mn = 1e9;
    for (int i = 0; i <= 100; ++i) for (int j = 0; j <= 100; ++j) {
      mn = min(mn, i * x + j * y + c[i][j]);
    }
    if (d[x][y] != mn) return cout << "Impossible" << '\n', 0;
  }
  cout << "Possible" << '\n';
  int n = 202, m = 100 + 100 + 101 * 101;
  cout << n << ' ' << m << '\n';
  for (int i = 1; i <= 100; ++i) cout << i << ' ' << i + 1 << " X\n";
  for (int i = 102; i < 202; ++i) cout << i << ' ' << i + 1 << " Y\n";
  for (int i = 0; i <= 100; ++i) for (int j = 0; j <= 100; ++j) {
    cout << i + 1 << ' ' << 202 - j << ' ' << c[i][j] << '\n';
  }
  cout << 1 << ' ' << 202 << '\n';
}