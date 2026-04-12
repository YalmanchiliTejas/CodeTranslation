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
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void add_edge2(Graph &g, int s, int d, Weight w){
  g[s].push_back(Edge(s,d,w));
  g[d].push_back(Edge(d,s,0));
}

#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight edmonds_karp(Graph &g, int s, int t) {
  int n = g.size();
  Matrix flow(n, Array(n)), capacity(n, Array(n));
  REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;
  
  Weight total = 0;
  while(1) {
    queue<int> Q; Q.push(s);
    vector<int> prev(n, -1); prev[s] = s;
    while(!Q.empty() && prev[t] < 0) { // s から t へ流せる路をBFSで見つける。
      int u = Q.front(); Q.pop();
      REP(v, n) if (prev[v] < 0 && RESIDUE(u, v) > 0) { // Spaghetti Source と変えた。
        prev[v] = u;
        Q.push(v);
      }
    }
    if (prev[t] < 0) return total;
    Weight inc = INF;
    for (int j=t; prev[j]!=j; j=prev[j])
      inc = min(inc, RESIDUE(prev[j], j));
    for (int j=t; prev[j]!=j; j=prev[j])
      flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc; // 逆辺のflow から引くことで押し戻せるようにする。
    // つまり、flow が流れたところの逆向きの辺に関してRESIDUE がその分大きくなる。
    total += inc;
  }
}

int H,W,C,M,NW,NC,NM;
int SUM;
int SOURCE() { return SUM; }
int SINK() { return SUM+1; }
int NW_IN() { return SUM+2; }
int NW_OUT() { return SUM+3; }
int NC_IN() { return SUM+4; }
int NC_OUT() { return SUM+5; }
int NM_IN() { return SUM+6; }
int NM_OUT() { return SUM+7; }
int HERO(int i) { return i; }
int WARRIOR_IN(int i) { return H+i; }
int WARRIOR_OUT(int i) { return H+W+i; }
int CLERIC_IN(int i) { return H+W*2+i; }
int CLERIC_OUT(int i) { return H+W*2+C+i; }
int MAGE_IN(int i) { return H+W*2+C*2+i; }
int MAGE_OUT(int i) { return H+W*2+C*2+M+i; }

int main() {
  while(cin>>H>>W>>C>>M>>NW>>NC>>NM, H!=-1) {
    SUM = H+W*2+C*2+M*2;
    Graph g(SUM+8);
    REP(i,W) {
      int n; cin >> n;
      REP(j,n) {
        int a; cin >> a; a--;
        add_edge2(g, HERO(a), WARRIOR_IN(i), 1);
      }
    }
    REP(i,C) {
      int n; cin >> n;
      REP(j,n) {
        int a; cin >> a; a--;
        add_edge2(g, WARRIOR_OUT(a), CLERIC_IN(i), 1);
      }
    }
    REP(i,M) {
      int n; cin >> n;
      REP(j,n) {
        int a; cin >> a; a--;
        add_edge2(g, CLERIC_OUT(a), MAGE_IN(i), 1);
      }
    }
    
    REP(i,H) {
      add_edge2(g, SOURCE(), HERO(i), 1);
      add_edge2(g, HERO(i), NW_IN(), 1);
    }
    add_edge2(g, NW_IN(), NW_OUT(), NW);
    REP(i,W) {
      add_edge2(g, WARRIOR_IN(i), WARRIOR_OUT(i), 1);
      add_edge2(g, WARRIOR_OUT(i), NC_IN(), 1);
    }
    add_edge2(g, NC_IN(), NC_OUT(), NC);
    REP(i,C) {
      add_edge2(g, CLERIC_IN(i), CLERIC_OUT(i), 1);
      add_edge2(g, NW_OUT(), CLERIC_IN(i), 1);
      add_edge2(g, CLERIC_OUT(i), NM_IN(), 1);
    }
    add_edge2(g, NM_IN(), NM_OUT(), NM);
    REP(i,M) {
      add_edge2(g, MAGE_IN(i), MAGE_OUT(i), 1);
      add_edge2(g, NC_OUT(), MAGE_IN(i), 1);
      add_edge2(g, MAGE_OUT(i), SINK(), 1);
    }
    add_edge2(g, NM_OUT(), SINK(), INF);
    cout << edmonds_karp(g, SOURCE(), SINK()) << endl;
  }
}