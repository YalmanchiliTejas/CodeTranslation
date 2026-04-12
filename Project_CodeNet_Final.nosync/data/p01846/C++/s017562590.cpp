#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


V<string> split(const string& s, char c) {
  V<string> res;
  stringstream ss(s);
  string t;
  while (getline(ss, t, c)) {
    res.push_back(t);
  }
  return res;
}

VV<> convert(const string& s) {
  VV<> res;
  for (const auto& e : split(s, '/')) {
    V<> curr;
    for (char c : e) {
      if (c == 'b') {
        curr.push_back(1);
      } else {
        while (c-- > '0') curr.push_back(0);
      }
    }
    res.push_back(curr);
  }
  return res;
}

string invert(const VV<>& a) {
  int h = a.size();
  string res;
  for (int i = 0; i < h; ++i) {
    if (i) res += '/';
    int w = a[i].size();
    int t = 0;
    for (int j = 0; j < w; ++j) {
      if (a[i][j]) {
        res += 'b';
      } else {
        ++t;
        if (j == w - 1 or a[i][j + 1]) {
          res += '0' + t;
          t = 0;
        }
      }
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  while (true) {
    string s; cin >> s;
    if (s == "#") break;
    auto a = convert(s);
    for (int _ = 0; _ < 2; ++_) {
      int i, j; cin >> i >> j, --i, --j;
      a[i][j] ^= 1;
    }
    s = invert(a);
    cout << s << '\n';
  }
}
