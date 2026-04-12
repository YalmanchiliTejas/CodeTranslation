#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

const int INF = 10000000;
typedef pair<int, int> P;
int ans = 0;

void dfs(const Graph &G, int v, vector<bool> &seen) {
  seen[v] = true;
  int loop_times = 0;
  for (auto next_v : G[v]) {
    if (seen[next_v]) {
      continue;
    }
    vector<bool> next_seen;
    next_seen = seen;
    dfs(G, next_v, next_seen);
    loop_times++;
  }
  if (loop_times == 0) {
    // cout << v << " "
    //      << "finish" << endl;
    ans++;
    for (int i = 1; i < seen.size(); i++) {
      // cout << seen[i] << endl;
      if (seen[i] == false) {
        ans--;
        break;
      }
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N + 1);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<bool> seen;
  seen.assign(N + 1, false);
  dfs(G, 1, seen);
  cout << ans << endl;
  return 0;
}
