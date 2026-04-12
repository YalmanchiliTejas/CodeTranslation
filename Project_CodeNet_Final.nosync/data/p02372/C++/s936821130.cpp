#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T1, class T2> inline void minup(T1& m, T2 x){ if(m>x) m=static_cast<T2>(x); }
template<class T1, class T2> inline void maxup(T1& m, T2 x){ if(m<x) m=static_cast<T2>(x); }

#define INF 1000000000
#define MOD 1000000009
#define EPS 1E-9

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) : src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

Weight visit(const Graph &g, Graph& T, int i, int j)
{
  if (T[i][j].weight >= 0) return T[i][j].weight;
  T[i][j].weight = g[i][j].weight;
  int u = T[i][j].dst;
  rep(k, T[u].size()) {
    if (T[u][k].dst == i) continue;
    T[i][j].weight = max(T[i][j].weight, visit(g,T,u,k)+g[i][j].weight);
  }
  return T[i][j].weight;
}

vector<Weight> HeightOfTree(const Graph& g)
{
  const int n = g.size();
  Graph T(g); // memoise on tree
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < T[i].size(); ++j)
      T[i][j].weight = -1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < T[i].size(); ++j)
      if (T[i][j].weight < 0)
        T[i][j].weight = visit(g, T, i, j);

  vector<Weight> ht(n); // gather results
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < T[i].size(); ++j)
      ht[i] = max(ht[i], T[i][j].weight);
  return ht;
}

int n;
int s, t;
Weight w;

int main()
{
  cin >> n;
  Graph g(n);
  rep(i, n){
    cin >> s >> t >> w;
    g[s].pb(Edge(s, t, w));
    g[t].pb(Edge(t, s, w));
  }

  vi res = HeightOfTree(g);

  vrep(v, res) cout << *v << endl;

  return 0;
}