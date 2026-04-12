#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef int Weight;
Weight INF = 1000000000;
struct Edge{
  int src, dest; Weight weight;
  bool operator < (const Edge &rhs) const {return weight > rhs.weight;}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void dijkstra(Graph &g, Array &d, int s) {
  d.assign(g.size(), INF);
  d[s] = 0;
  typedef pair<Weight,int> P;
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0, s));
  while (!que.empty()) {
    Weight dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    REP(i, g[v].size()) {
      Edge e = g[v][i];
      if (d[e.dest] > d[v] + e.weight) {
        d[e.dest] = d[v] + e.weight;
        que.push(P(d[e.dest], e.dest));
      }
    }
  }
}

int main() {
  int di[]={1,0,-1,0};
  int dj[]={0,1,0,-1};
  int r,c,m;
  cin>>r>>c>>m;
  vector<string> t(r);
  REP(i,r)cin>>t[i];
  int n=r*c;
  vector<vector<int>> dir(n,vector<int>(n));
  Graph g(n);
  REP(i,r)REP(j,c){
    if(t[i][j] != '.') continue;
    int p=i*c+j;
    REP(k,4){
      int ni=i+di[k];
      int nj=j+dj[k];
      if(ni<0||nj<0||ni>=r||nj>=c) continue;
      int np = ni*c+nj;
      if(t[ni][nj] == '.')
        g[p].push_back((Edge){p, np, 1});
    }
  }
  Matrix dist(n, Array(n));
  REP(i,n) dijkstra(g, dist[i], i);
  REP(i,r)REP(j,c){
    int p=i*c+j;
    REP(k,4){
      int ni=i+di[k];
      int nj=j+dj[k];
      if(ni<0||nj<0||ni>=r||nj>=c) continue;
      int np = ni*c+nj;
      REP(l,n){
        if(dist[p][l] > dist[np][l])
          dir[p][l] = k;
      }
    }
  }
  vector<int> con(n), clg(n), coff(n);
  REP(i,n) cin>>clg[i];
  REP(i,n) cin>>con[i];
  REP(i,n) cin>>coff[i];
  vector<int> q;
  REP(i,m){
    int ri,rj;
    cin>>ri>>rj;
    q.push_back(ri*c+rj);
  }
  vector<int> rm;
  REP(i,m-1){
    int fr = q[i];
    int to = q[i+1];
    for (int j = fr; j != to;) {
      rm.push_back(j);
      int k = dir[j][to];
      j += di[k]*c + dj[k];
    }
  }
  rm.push_back(q.back());
  vector<int> old(n,-1);
  int64_t sum = 0;
  REP(i,rm.size()) {
    int ri=rm[i];
    if (old[ri] == -1)
      sum += con[ri] + coff[ri];
    else {
      int callon = (i-old[ri]) * clg[ri];
      int coffon = con[ri] + coff[ri];
      sum += min(callon, coffon);
    }
    old[ri] = i;
  }
  cout << sum << endl;
  return 0;
}