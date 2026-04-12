#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

typedef long long i64;
typedef pair<i64, int> pii;

const int MAX_N = 100005, MOD = 1000000007;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

class Edge {
public:
  int nxt, to, w;
} e[MAX_N << 2];
int head[MAX_N], cnt;
void addedge(int u, int v, int w) {
  e[++cnt] = (Edge){head[u], v, w}, head[u] = cnt;
  e[++cnt] = (Edge){head[v], u, w}, head[v] = cnt;
}

int N, M, S, T;
i64 dis1[MAX_N], dis2[MAX_N];

priority_queue<pii, vector<pii>, greater<pii> > q;

void dijkstra(int s, i64 *dis) {
  static bool vis[MAX_N];
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= N; ++i) dis[i] = inf;
  dis[s] = 0;
  q.push(make_pair(0, s));

  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
      if (dis[e[i].to] > dis[u] + e[i].w) {
	dis[e[i].to] = dis[u] + e[i].w;
	q.push(make_pair(dis[e[i].to], e[i].to));
      }
  }
}

i64 way1[MAX_N], way2[MAX_N];

vector<int> G[MAX_N];
bool vis[MAX_N];
int st[MAX_N], top;

void dfs(int u) {
  vis[u] = 1;
  for (int i = 0; i < G[u].size(); ++i)
    if (!vis[G[u][i]])
      dfs(G[u][i]);
  st[++top] = u;
}

void get(int s, i64 *dis, i64 *way) {
  memset(vis, 0, sizeof vis), top = 0;
  for (int i = 1; i <= N; ++i) G[i].clear();
  for (int u = 1; u <= N; ++u)
    for (int i = head[u]; i; i = e[i].nxt)
      if (dis[e[i].to] == dis[u] + e[i].w) 
	G[e[i].to].push_back(u);
  for (int i = 1; i <= N; ++i)
    if (!vis[i])
      dfs(i);
  way[s] = 1;
  for (int i = 1; i <= N; ++i) {
    int u = st[i];
    for (int j = 0; j < G[u].size(); ++j)
      way[u] = (way[u] + way[G[u][j]]) % MOD;
  }
}

int main() {
  scanf("%d%d", &N, &M);
  scanf("%d%d", &S, &T);
  for (int i = 1; i <= M; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addedge(u, v, w);
  }
  
  dijkstra(S, dis1);
  dijkstra(T, dis2);

  get(S, dis1, way1);
  get(T, dis2, way2);

  assert(way1[T] == way2[S]);
  i64 result = way1[T] * way2[S] % MOD;
  for (int u = 1; u <= N; ++u) {
    if (dis1[u] == dis2[u] && dis1[u] + dis2[u]  == dis1[T]) 
      result = (result - way1[u] * way2[u] % MOD * way1[u] % MOD * way2[u] % MOD) % MOD;
  }
  for (int u = 1; u <= N; ++u)
    for (int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (dis1[u] + e[i].w + dis2[v] != dis1[T]) continue;
      if (dis1[u] * 2 < dis1[T] && dis2[v] * 2 < dis1[T]) {
	result = (result - way1[u] * way2[v] % MOD * way1[u] % MOD * way2[v] % MOD) % MOD;
      }
    }
  printf("%lld\n", (result + MOD) % MOD);
  return 0;
}
