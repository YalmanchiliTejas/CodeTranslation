#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; string s; cin >> n >> s >> k; --k;
  for(auto &c : s) {
    if(c != s[k]) {
      c = '*';
    }
  }
  cout << s << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
