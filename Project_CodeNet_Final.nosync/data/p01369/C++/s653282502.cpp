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
  string t = "yuiophjklnm";
  while (true) {
    string s; cin >> s;
    if (s == "#") break;
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
      bool b0 = find(begin(t), end(t), s[i]) != end(t);
      bool b1 = find(begin(t), end(t), s[i + 1]) != end(t);
      res += b0 ^ b1;
    }
    cout << res << '\n';
  }
}
