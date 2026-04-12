#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  int k; cin >> k, --k;
  for (auto&& c : s) if (c != s[k]) {
    c = '*';
  }
  cout << s << '\n';
}