// -----------------------------------
// Author     : MatsuTaku
// Country    : Japan
// Created    : 04/09/20 20:59:36
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n,m; cin>>n>>m;
  vector<int> graph[n];
  for (int i = 0; i < m; i++) {
    int a,b; cin>>a>>b; a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  struct State {
    set<int> h;
    int c;
  };
  queue<State> qs;
  qs.push({{}, 0});
  int ans = 0;
  while (not qs.empty()) {
    auto q = qs.front(); qs.pop();
    q.h.insert(q.c);
    for (auto t:graph[q.c]) {
      if (q.h.count(t))
        continue;
      if (q.h.size()+1 == n) {
        ans++;
        continue;
      }
      qs.push({q.h, t});
    }
  }
  cout << ans << endl;

  return 0;
}
