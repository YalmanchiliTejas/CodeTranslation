#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  V<string> a(h); for (int i = 0; i < h; i++) cin >> a[i];
  V<> ei(h), ej(w);
  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if (a[i][j] == '#') ei[i] = ej[j] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) if (ei[i] and ej[j]) cout << a[i][j];
    if (ei[i]) cout << '\n';
  }
}