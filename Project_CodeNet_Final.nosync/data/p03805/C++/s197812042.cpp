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

int N, M;
vector<int> g[10];

int dfs(int u, bool used[], int cnt)
{
  if(used[u]) return 0;
  if(cnt == N-1) return 1;
  used[u] = true;
  int ret = 0;
  for(int v : g[u]) {
    ret += dfs(v, used, cnt+1);
  }
  used[u] = false;
  return ret;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M;

  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bool used[N] = {};
  cout << dfs(0, used, 0) << endl;

  return 0;
}
