#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;

typedef int Weight;
const int INF = 1e9;

struct Edge {
  int src,dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight :
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

int k;
set<int> ss;

void dfs(Graph &g, int v) {
    ss.insert(v);
    for(int i=0; i<g[v].size(); ++i) {
        dfs(g,g[v][i].dst);
    }
}

#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlow(Graph graph,int s,int t) {
  int n = graph.size();
  Weight total = 0;
  Matrix flow(n, Array(n)),capacity(n, Array(n));

  //ツ療猟静堋行ツ療アツづ個渉可甘コツ可サ
  for(int i=0; i<n; ++i)
    for(vector<Edge>::iterator it = graph[i].begin(); it != graph[i].end(); ++it)
      capacity[it->src][it->dst] += it->weight;

  while(1) {
    queue<int> Q;
    Q.push(s);
    vector<int> prev(n, -1);
    prev[s] = s;
    //ツ堕敖妥・ツ路ツづ個板ュツ個ゥ
    while(!Q.empty() && prev[t] < 0) {
      int u = Q.front();
      Q.pop();
      for(vector<Edge>::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
	if(prev[it->dst] < 0 && RESIDUE(u, it->dst) > 0) {
	  prev[it->dst] = u;
	  Q.push(it->dst);
	}
      }
    }

    if(prev[t] < 0) return total;
    Weight inc = INF;

    //flowツづ個更ツ新
    for(int j = t; prev[j] != j; j = prev[j])
      inc = min(inc, RESIDUE(prev[j], j));
    for(int j = t; prev[j] != j; j = prev[j])
      flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
    total += inc;
  }
  return 0;
}


int main() {
    int n,m,x,y,w;
    while(cin>>n>>m, n|m) {
        Graph g(n);
        Graph rg(n);
        int ans = 0;
        for(int i=0; i<m; ++i) {
            cin>>x>>y>>w;
            if(w <= 0) {
                ans += w;
            }else{
                g[x].push_back(Edge(x,y,w));
                g[y].push_back(Edge(y,x,w));
            }
        }

        int k = 1<<29;
        for(int i=1; i<n; ++i) {
            k = min(k, maximumFlow(g,0,i));
        }
        cout<<ans+k<<endl;
    }
}