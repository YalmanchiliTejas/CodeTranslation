#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MON 1000000007
#define INF (1<<29)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

vector<int> far(10800);
vector<int> up(10800);
int u, v, w, n;
class Edge{
public:
  int from, to, rev;
  Int cost, lim;
  Edge(int from, int to, Int cost, int lim = -1, Int rev = -1):
    from(from),to(to),cost(cost),lim(lim),rev(rev){}
};


class Graph{
public:
  int n;
  int m;
  vector<vector<Edge>> edge;
  Graph(int n = 0):n(n),m(0){
    edge = vector<vector<Edge>>(n);
  }
  void add_edge(int from, int to, int cost = 1, int lim = -1)
  {
    if(lim == -1){
      edge[from].push_back(Edge(from, to, cost));
      return;
    }
    edge[from].push_back(Edge(from, to, cost, lim, edge[to].size()));
    edge[to].push_back(Edge(to, from, -cost, 0, edge[from].size() - 1));
  }
};

Graph g;

void dfs0(int x, int last = -1){
  for(auto e: g.edge[x]){
    if(e.to != last)dfs0(e.to, x);
  }
  if(last == -1)return;
  auto it = g.edge[x].begin();
  while(it->to != last)it++;
  g.edge[x].erase(it);
  return;
}

void dfs1(int x, int last = -1){
  far[x] = 0;
  for(auto e:g.edge[x]){
    if(e.to == last)continue;
    dfs1(e.to, x);
    far[x] = max(far[e.to] + e.cost, far[x]);
  }
  for(int i = 1;i < g.edge[x].size();i++){
    if(far[g.edge[x][0].to] + g.edge[x][0].cost < far[g.edge[x][i].to] + g.edge[x][i].cost)
      swap(g.edge[x][0], g.edge[x][i]);
  }
  for(int i = 2;i < g.edge[x].size();i++){
    if(far[g.edge[x][1].to] + g.edge[x][1].cost < far[g.edge[x][i].to] + g.edge[x][i].cost)
      swap(g.edge[x][1], g.edge[x][i]);
  }
}

void dfs2(int x, int last = -1, int w = 0){
  if(last != -1){
    if(g.edge[last][0].to == x){
      if(g.edge[last].size() > 1)up[x] = far[g.edge[last][1].to] + g.edge[last][1].cost + w;
      else up[x] = w;
    }
    else up[x] = far[last] + w;
    up[x] = max(up[x], up[last] + w);
  }
  for(auto e:g.edge[x]){
    if(e.to == last)continue;
    dfs2(e.to, x, e.cost);
  }
}

int main(){
  cin >> n;
  g = Graph(n);
  for(int i = 0;i < n-1;i++){
    cin >> u >> v >> w;
    g.add_edge(u, v, w);
    g.add_edge(v, u, w);
  }
  dfs0(0);
  dfs1(0);
  dfs2(0);
  for(int i = 0;i < n;i++){
    cout << max(far[i], up[i]) << endl;
  }
  return 0;
}
