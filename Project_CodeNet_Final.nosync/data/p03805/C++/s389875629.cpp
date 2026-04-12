#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

vector<vector<int>> G;

int dfs(int i, set<int> visited) {
  visited.insert(i);
  if (visited.size() == G.size()) {
    return 1;
  }

  int total = 0;
  for (int v : G[i]) {
    if (!visited.count(v)) {
      total += dfs(v, visited);
    }
  }
  return total;
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cout << dfs(0, {}) << endl;
}
