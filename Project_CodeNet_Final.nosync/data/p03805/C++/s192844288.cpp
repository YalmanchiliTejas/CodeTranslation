#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> edges(N, vector<bool>(N, false));
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a][b] = edges[b][a] = true;
  }

  vector<int> route(N);
  iota(route.begin(), route.end(), 0);
  int ans{};
  do {
    bool ok{true};
    for (int i{}; i < N - 1; ++i) {
      if (!edges[route[i]][route[i + 1]]) {
        ok = false;
        break;
      }
    }
    if (ok)
      ++ans;
  } while (next_permutation(route.begin() + 1, route.end()));

  cout << ans << endl;
  return 0;
}
