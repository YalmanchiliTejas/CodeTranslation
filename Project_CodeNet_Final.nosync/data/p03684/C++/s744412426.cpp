#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;
typedef pair<int, int> Pair;
typedef pair<int, Pair> Edge;

int N;
LLI ans;
int par[114514];
int myrank[114514];
vector<Pair> xs;
vector<Pair> ys;
vector<Edge> es;

int find(int v) {
  if (par[v] == v) return v;
  return par[v] = find(par[v]);
}

int same(int u, int v) {
  return find(u) == find(v);
}

void unite(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (myrank[u] > myrank[v]) par[v] = u;
  else {
    par[u] = v;
    if (myrank[u] == myrank[v]) myrank[v]++;
  }
}

int main() {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    xs.emplace_back(Pair(x, i));
    ys.emplace_back(Pair(y, i));
    par[i] = i;
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  for (int i=1; i<N; i++) {
    es.emplace_back(Edge(xs[i].first-xs[i-1].first, 
         Pair(xs[i-1].second, xs[i].second)));
    es.emplace_back(Edge(ys[i].first-ys[i-1].first, 
         Pair(ys[i-1].second, ys[i].second)));
  }
  sort(es.begin(), es.end());
  for (auto &e : es) {
    int u, v;
    tie(u, v) = e.second;
    if (same(u, v)) continue;
    unite(u, v);
    ans += e.first;
  }
  printf("%lld\n", ans);
}
    
  