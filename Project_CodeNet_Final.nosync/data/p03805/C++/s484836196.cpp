#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()

int N, M;
vector<set<int>> path;

int visit(set<int> visited, int now) {
  visited.insert(now);
  if (visited.size() == (unsigned) N) return 1;
  int ways = 0;
  for(auto i : path[now]) {
    if (visited.find(i) != visited.end()) continue;
    ways += visit(visited, i);
  }
  return ways;
}

signed main() {
  cin >> N >> M;
  rep(i, N) path.push_back({});
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    path[a-1].insert(b-1);
    path[b-1].insert(a-1);
  }
  cout << visit({}, 0) << endl;
}
