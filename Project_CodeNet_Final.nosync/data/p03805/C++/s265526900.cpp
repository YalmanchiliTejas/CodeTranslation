#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int n, m;
vector<int> graph[10];

int dfs(int u, int p, int bit)
{
  if(bit == (1<<n)-1) return 1;
  int ret = 0;
  for(int v : graph[u]) {
    if(v == p) continue;
    if(!((bit >> v) & 1)) ret += dfs(v, u, bit | (1<<v));
  }
  return ret;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  cout << dfs(0, -1, 1) << endl;

  return 0;
}
