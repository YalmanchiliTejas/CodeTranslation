#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 100005;

class Edge {
public:
  int nxt, to;
} e[MAX_N << 1];

int head[MAX_N], cnt, Nx;

void addedge(int u, int v) {
  e[++cnt] = (Edge){head[u], v}, head[u] = cnt;
  e[++cnt] = (Edge){head[v], u}, head[v] = cnt;
}

int dep[MAX_N], fa[MAX_N], id[MAX_N];
bool vis[MAX_N];

void dfs(int u, int v) {
  id[u] = u, fa[u] = v, dep[u] = dep[v] + 1;
  for (int i = head[u]; i; i = e[i].nxt)
    if (e[i].to != v)
      dfs(e[i].to, u);
}

bool cmp(int x, int y) {
  return dep[x] > dep[y];
}

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1, u, v; i < N; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
  }
  
  dfs(1, 0);

  sort(id + 1, id + N + 1, cmp);

  vis[0] = 1;
  bool flag = 1;
  for (int i = 1; i <= N; ++i) {
    if (vis[id[i]]) continue;
    if (vis[fa[id[i]]]) flag = 0;
    vis[fa[id[i]]] = 1;
  }

  if (flag) puts("Second");
  else puts("First");
  
  return 0;
}
