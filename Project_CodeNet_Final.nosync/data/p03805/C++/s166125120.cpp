#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<int> > adj(N + 1, vector<int>(N + 1, 0));
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a][b] = adj[b][a] = 1;
  }

  vector<int> v;
  for (int i = 2; i <= N; ++i) { v.push_back(i); }
  sort(v.begin(), v.end());

  int ans = 0;
  do {
    int u = 1;
    bool ok = true;
    for (int i = 0; i < (int)v.size(); ++i) {
      if (adj[u][v[i]] != 1) {
        ok = false;
        break;
      }
      u = v[i];
    }
    if (ok) { ++ans; }
  } while (next_permutation(v.begin(), v.end()));

  printf("%d\n", ans);
  return 0;
}
