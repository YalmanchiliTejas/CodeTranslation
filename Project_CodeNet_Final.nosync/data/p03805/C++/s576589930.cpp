#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Solve(const vector<int>& order, const vector<vector<bool>>& edges) {
  int from = 1;
  for (int to : order) {
    if (!edges[from][to]) {
      return false;
    }
    from = to;
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> edges(N+1, vector<bool>(N+1));
  for (int m = 0; m < M; ++m) {
    int a, b;
    cin >> a >> b;
    edges[a][b] = true;
    edges[b][a] = true;
  }
  vector<int> order(N-1);
  for (int n = 2; n <= N; ++n) {
    order[n-2] = n;
  }
  int result = 0;
  do {
    if (Solve(order, edges)) {
      ++result;
    }
  } while (next_permutation(order.begin(), order.end()));
  cout << result << endl;
  
  return 0;
}
