// GRL_5_B Height of a Tree

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

#define MAXN 10010

using namespace std;

struct edge {
  int to, wt;
  edge(int to, int wt) : to(to), wt(wt) {}
};

vector<edge> adj[MAXN];
bool visited[MAXN];
int LD[MAXN];

void dfs(int i, int ld) {
  if (visited[i])
    return;
  visited[i] = true;
  LD[i] = max(LD[i], ld);
  for (auto &e : adj[i])
    if (!visited[e.to])
      dfs(e.to, ld + e.wt);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0, s, t, wt; i < n - 1; ++i) {
    scanf("%d%d%d", &s, &t, &wt);
    adj[s].emplace_back(t, wt);
    adj[t].emplace_back(s, wt);
  }
  memset(LD, 0, sizeof(LD));

  for (int root = 0; root < n; ++root) {
    if (adj[root].size() == 1) {
      memset(visited, 0, sizeof(visited));
      dfs(root, 0);
    }
  }
  for (int root = 0; root < n; ++root) {
    printf("%d\n", LD[root]);
  }
}
