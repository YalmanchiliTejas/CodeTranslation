#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

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

  vector<ll> nodes(N, 0);
  for (ll i = 0; i < N; i++) {
    nodes[i] = i;
  }

  ll ans = 0;
  do {
    if (nodes[0] != 0) continue;

    bool ok = true;
    for (ll i = 0; i < N - 1; i++) {
      if (Graph[nodes[i]][nodes[i + 1]] == 0) {
        ok = false;
        break;
      }
    }

    if (ok) ans++;
  } while (next_permutation(nodes.begin(), nodes.end()));

  cout << ans << endl;
}