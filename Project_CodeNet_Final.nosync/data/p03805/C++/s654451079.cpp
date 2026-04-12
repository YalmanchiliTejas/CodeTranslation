#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);
bool vis[8];
int N, M;
vector<int> g[8];
int ans = 0;

void dfs(int x, int cnt) {
  if (cnt == N) {
    ans++;
    return;
  }

  for (auto y : g[x]) {
    if (vis[y]) continue;

    vis[y] = true;
    dfs(y, cnt+1);
    vis[y] = false;
  }
}


int main() {
  cin >> N >> M;
  rep(i, M) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vis[0] = true;
  for (auto x : g[0]) {
    vis[x] = true;
    dfs(x, 2);
    vis[x] = false;
  }

  cout << ans << endl;

  return 0;
}