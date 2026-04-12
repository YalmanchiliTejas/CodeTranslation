#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, total = 0;
vector<int> subset;
vector<vector<int>> connections;

void solve(int x) {
  if (subset.size()==n) {
    total++;
    return;
  }
  
  for (auto i : connections[x]) {
    if (find(subset.begin(),subset.end(),i) != subset.end()) continue;
    subset.push_back(i);
    solve(i);
    subset.pop_back();
  }
  
  return;
}

int main() {
  cin >> n >> m;
  
  for (int i=0; i<=n; i++) {
    connections.push_back({});
  }
  
  for (int i=0; i<m; i++) {
    cin >> a >> b;
    connections[a].push_back(b);
    connections[b].push_back(a);
  }
  
  subset.push_back(1);
  solve(1);
  
  cout << total;
  
  return 0;
}