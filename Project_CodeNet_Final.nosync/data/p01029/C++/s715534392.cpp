#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  string s(n, '.');
  for(char &c : s) cin >> c;

  vector<vector<int>> G(n);
  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  for(int v = 0; v < n; ++v) {
    if(s[v] != '?') continue;

    vector<bool> used(26, false);

    for(const auto &to : G[v]) {
      if(s[to] != '?') {
	used[s[to] - 'a'] = true;
      }
    }

    for(int i = 0; i < 26; ++i) {
      if(!used[i]) {
	s[v] = 'a' + i;
	break;
      }
    }
  }

  cout << s << endl;

  return 0;
}
