#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;

typedef ll Weight;
struct Edge {
    int src, dst;
    Weight weight;
    Edge():src(0),dst(0),weight(0){}
    Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void Dijkstra(const Graph &g, int s,
              vector<Weight> &dist, vector<ll> &cnt) {
    int n = (int)g.size();
    dist.assign(n, INF); dist[s] = 0;
    cnt.assign(n, 0); cnt[s] = 1;
    priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
    vector<bool> visit(n,false);
    for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (visit[e.dst]) continue;
        visit[e.dst] = true;
        for(Edge f: g[e.dst]) {
            if (dist[f.dst] > e.weight+f.weight) {
                dist[f.dst] = e.weight+f.weight;
                cnt[f.dst]=cnt[f.src];
                Q.push(Edge(f.src, f.dst, e.weight+f.weight));
            }else if(dist[f.dst] == e.weight+f.weight){
              cnt[f.dst]=(cnt[f.dst]+cnt[f.src])%MOD;
            }
        }
    }
}

int main() {
  int N,M;cin >> N >> M;
  int S,T;cin >> S >> T;S--;T--;
  Graph g(N);
  Edges E(M);
  repeat(i,M){
    int U,V;
    Weight D;
    cin >> U >> V >> D;
    U--;V--;
    E[i] = Edge(U,V,D);
    g[U].push_back({U,V,D});
    g[V].push_back({V,U,D});
  }
  vector<Weight> sdist,tdist;
  vll scnt,tcnt;
  Dijkstra(g,S,sdist,scnt);
  Dijkstra(g,T,tdist,tcnt);
  ll ans = scnt[T]*(scnt[T])%MOD;
  repeat(i,M){
    int u=E[i].src;
    int v=E[i].dst;
    if(sdist[u]>sdist[v]){
      swap(u,v);
    }
    if(sdist[u]+E[i].weight+tdist[v]!=sdist[T]) continue;
    if(2*sdist[u] >= sdist[T] || sdist[T] >= 2*sdist[v]) continue;
    ll tmp = scnt[u]*tcnt[v]%MOD;
    ll dupl = tmp*(tmp)%MOD;
    ans = (ans-dupl+MOD)%MOD;
  }
  repeat(i,N){
    if(sdist[i]+tdist[i] != sdist[T]) continue;
    if(sdist[i] != tdist[i]) continue;
    ll tmp = scnt[i]*tcnt[i]%MOD;
    ll dupl = tmp*(tmp)%MOD;
    ans = (ans-dupl+MOD)%MOD;
  }

  cout << ans << endl;
  return 0;
}
