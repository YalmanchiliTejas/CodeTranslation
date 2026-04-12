#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll res = 0;
int N, M;
void solve(long long curr, map<int, vector<int>>& m, set<int>& seen) {
  if (seen.size() == N-1) {
    res++;
    return;
  }
  seen.insert(curr);
  for (auto neigh : m[curr]) {
    if (seen.count(neigh)) continue;
    solve(neigh, m, seen);
  }
  seen.erase(curr);
}

int main() {
  cin >> N >> M;
  map<int, vector<int>> m;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    m[a].push_back(b);
    m[b].push_back(a);
  }
  set<int> seen;
  solve(1, m, seen);
  cout << res << endl;
  return 0;
}
