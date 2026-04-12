#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<int>> g;

bool solve();

int main() {
  cin >> n;
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].insert(--b);
    g[b].insert(a);
  }
  if (solve())
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}

bool solve() {
  vector<int> ch;
  queue<int> bl, wh;
  ch.assign(n, 0);
  for (int i = 0; i < n; ++i)
    if (g[i].size() == 1) bl.push(i);
  while (bl.size() || wh.size()) {
    while (bl.size()) {
      int now = bl.front();
      bl.pop();
      for (auto to : g[now]) {
        g[to].erase(now);
        if (ch[to]) return 1;
        ch[to] = 1;
        if (g[to].size() == 1) wh.push(to);
      }
    }
    while (wh.size()) {
      int now = wh.front();
      wh.pop();
      for (auto to : g[now]) {
        g[to].erase(now);
        if (g[to].size() == 1) {
          if (ch[to])
            wh.push(to);
          else
            bl.push(to);
        }
        if (g[to].size() == 0 && !ch[to]) return 1;
      }
    }
  }
  return 0;
}