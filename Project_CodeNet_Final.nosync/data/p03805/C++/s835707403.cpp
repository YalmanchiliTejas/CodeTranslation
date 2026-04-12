#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
vector<vector<int>> P;
int N, M, ans;
void dfs(int v, int cnt, vector<int> vs)
{
  cnt++;
  if (cnt == N) ans++;
  if (vs[v]) return;
  vs[v] = 1;
  for (auto t : P[v]) {
    if (vs[t]) continue;
    dfs(t, cnt, vs);
  }
}

int main(void)
{
  cin >> N >> M;
  P.resize(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--;  y--;
    P[x].push_back(y);
    P[y].push_back(x);
  }
  
  vector<int> vs(N, 0);
  dfs(0, 0, vs);
  cout << ans << endl;
  return 0;
}