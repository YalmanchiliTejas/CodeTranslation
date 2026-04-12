#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<int>> adj(N + 5, vector<int>(N + 5, 0));
  int a, b;
  for (int i = 0; i < M; ++i) {
    scanf("%d %d", &a, &b);
    adj[a][b] = adj[b][a] = 1;
  }

  vector<int> v;
  for (int i = 1; i <= N; ++i) { v.push_back(i); }

  int ans = 0;
  do {
    bool ok = true;
    for (int i = 0; i + 1 < N; ++i) {
      if (adj[v[i]][v[i + 1]] == 0) {
        ok = false;
        break;
      }
    }
    if (ok) { ++ans; }

  } while (next_permutation(v.begin() + 1, v.end()));

  printf("%d\n", ans);
  return 0;
}
