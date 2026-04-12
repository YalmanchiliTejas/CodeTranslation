#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

struct edge {
  int src, dst;
  int weight;
};
struct graph {
  int n;
  vector<edge> edges;
  graph(int n = 0) : n(n) { }
  void add_edge(int src, int dst, int weight) {
    n = max(n, max(src, dst)+1);
    edges.push_back({src, dst, weight});
  }
  vector<int> p; 
  int root(int i) { 
    return p[i] < 0 ? i : p[i] = root(p[i]); 
  }
  bool unite(int i, int j) {
    if ((i = root(i)) == (j = root(j))) return false;
    if (p[i] > p[j]) swap(i, j);
    p[i] += p[j]; p[j] = i;
    return true;
  }
  int kruskal() {
    p.assign(n, -1);
    sort(all(edges), [](edge x, edge y) {
        return x.weight < y.weight; 
    });
    int result = 0;
    for (auto e: edges) 
      if (unite(e.src, e.dst)) 
        result += e.weight;
    return result;
  }
};

int main(){
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  REP(i,N) cin >> x[i] >> y[i];

  vector<pair<int,int>> xi(N), yi(N);
  REP(i,N) {
    xi[i] = make_pair(x[i], i);
    yi[i] = make_pair(y[i], i);
  }
  sort(all(xi));
  sort(all(yi));

  graph g(N);
  REP(i,N - 1){
    g.add_edge(xi[i].snd, xi[i + 1].snd, abs(xi[i].fst - xi[i + 1].fst));
    g.add_edge(yi[i].snd, yi[i + 1].snd, abs(yi[i].fst - yi[i + 1].fst));
  }
  int ret = g.kruskal();

  cout << ret << endl;
  return 0;
}

