#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
  Edge(int src, int dst) : src(src), dst(dst) {}
};

bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool augment(const Graph& g, int u,
    vector<int>& matchTo, vector<bool>& visited) {
  if (u < 0) return true;
  FOR(e, g[u]) if (!visited[e->dst]) {
    visited[e->dst] = true;
    if (augment(g, matchTo[e->dst], matchTo, visited)) {
      matchTo[e->src] = e->dst;
      matchTo[e->dst] = e->src;
      return true;
    }
  }
  return false;
}

int bipartiteMatching(const Graph& g, int L, Edges& matching) {
  const int n = g.size();
  vector<int> matchTo(n, -1);
  int match = 0;
  REP(u, L) {
    vector<bool> visited(n);
    if (augment(g, u, matchTo, visited)) ++match;
  }
  REP(u, L) if (matchTo[u] >= 0) // make explicit matching
    matching.push_back( Edge(u, matchTo[u]) );
  return match;
}

int h[1000][1000];
int t[1000][1000];
int H, W;

bitset<1000> ok[1000];
pii v[1000];

bool check() {
  REP(i,W) ok[i].set();
  REP(y,H) {
    REP(x,W) v[x] = pii(h[y][x],x);
    sort(v,v+W,greater<pii>());
    int id = 0;
    bitset<1000> bits;
    bits.set();
    REP(x,W) {
      while(id<W&&v[id].first>=v[x].first) bits[v[id++].second] = 0;
      ok[v[x].second] &= bits;
    }
  }
  // REP(i, W) {
  //   REP(j,W) cout << ok[i][j];
  //   cout << endl;
  // }

  Graph g(2*W);
  bool f = 0;
  REP(i,W) {
    // g[i].push_back(Edge(i,W+i));
    // g[W+i].push_back(Edge(W+i,i));
    int c = 0;
    REP(j,W) {
      if(ok[i][j]) {
        ++c;
        g[i].push_back(Edge(i,W+j));
        g[W+j].push_back(Edge(W+j,i));
      }
    }
    f |= (c == W-1) ;
  }
  if (!f) return 0;
  
  Edges gomi;
  int r = W-bipartiteMatching(g,W,gomi);
  
  return r <= 2;
}

int main() {
  cin >> H >> W;
  REP(i,H)REP(j,W)cin>>h[i][j];
  if (!check()) goto no;
  REP(i,H)REP(j,W)t[i][j]=h[i][j];
  REP(i,H)REP(j,W)h[j][i]=t[i][j];
  swap(H,W);
  if (!check()) goto no;
  cout << "YES" << endl;
  return 0;
no:
  cout << "NO" << endl;
}