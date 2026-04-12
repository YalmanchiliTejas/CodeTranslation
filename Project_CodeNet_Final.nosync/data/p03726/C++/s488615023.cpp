#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

vector<vector<int>> edge;
int dfs(int node, vector<bool>& is_visited) {
  is_visited[node] = true;

  int odd = 0;
  for (int e : edge[node]) {
    if (!is_visited[e]) {
      int r = dfs(e, is_visited);
      if (r < 0) {
        return -1;
      }
      odd += r;
    }
  }
  if (odd >= 2) {
    return -1;
  } else if (odd == 1) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int N;
  cin >> N;

  edge.resize(N);
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  vector<bool> is_visited(N, false);
  int result = dfs(0, is_visited);
  cout << (result != 0 ? "First" : "Second") << endl;

  return 0;
}