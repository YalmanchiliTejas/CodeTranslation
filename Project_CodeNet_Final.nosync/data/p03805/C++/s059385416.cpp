#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<bool>> adj(N + 5, vector<bool>(N + 5));
  int a, b;
  for (int i = 0; i < M; ++i) {
    scanf("%d %d", &a, &b);
    adj[a][b] = adj[b][a] = true;
  }

  vector<int> V;
  for (int i = 1; i <= N; ++i) {
    V.push_back(i);
  }

  int ans = 0;
  sort(V.begin(), V.end());
  do {
    bool ok = true;
    for (int i = 0; i < N - 1; ++i) {
      if (not adj[V[i]][V[i + 1]]) {
        ok = false;
        break;
      }
    }
    if (ok) { ++ans; }
  } while (next_permutation(V.begin() + 1, V.end()));

  printf("%d\n", ans);
  return 0;
}
