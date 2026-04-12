#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

void bfs(ll v, vector<vector<int>> &Graph, vector<int> &seen, ll &res) {
  bool ok = true;
  for (ll i = 0; i < seen.size(); i++) {
    if (seen[i] == 0 && i != v) {
      ok = false;
      break;
    }
  }

  // cout << "visited: " << v << endl;
  // cout << "ok:" << ok << endl;

  if (ok) {
    res++;
    return;
  }

  seen[v] = 1;
  for (ll i = 0; i < Graph.size(); i++) {
    if (Graph[v][i] == 1 && seen[i] == 0) {
      bfs(i, Graph, seen, res);
    }
  }
  seen[v] = 0;
}

int main() {
  ll N, M;
  cin >> N >> M;

  vector<vector<int>> Graph(N, vector<int>(N, 0));

  for (ll i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    Graph[a-1][b-1] = 1;
    Graph[b-1][a-1] = 1;
  }

  vector<int> seen(N, 0);

  ll res = 0;
  bfs(0, Graph, seen, res);

  cout << res << endl;
}