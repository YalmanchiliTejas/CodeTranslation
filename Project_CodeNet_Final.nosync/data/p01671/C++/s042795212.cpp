#include <bits/stdc++.h>

//{{{ graph.hpp
#ifndef INCLUDE_GRAPH_HPP
#define INCLUDE_GRAPH_HPP
#include <vector>
namespace orislib {
struct Edge {
  typedef long long weight_t;
  int from, to, id;
  weight_t w;
  bool inMST;
  Edge(int from, int to, weight_t w, int id) : from(from), to(to), w(w), id(id), inMST(false) {}
  bool operator<(const Edge& e) const {
    return w != e.w ? w > e.w : from != e.from ? from < e.from : to < e.to;
  }
  static const weight_t INF;
};
const Edge::weight_t Edge::INF=INT_MAX;
typedef std::vector<Edge> Edges;
typedef std::vector<Edges> Graph;
}
#endif
//}}}
//{{{ uf.hpp
#ifndef INCLUDE_UF_HPP
#define INCLUDE_UF_HPP
#include <vector>
#include <algorithm>
namespace orislib {
namespace ds {
//{{{ UF merge, same, root, size, count
struct UF {
  std::vector<int> data;
  int cnt;
  UF(int n) : data(n, -1), cnt(n) {}
  bool merge(int a, int b){
    a = root(a);
    b = root(b);
    if (a != b){
      cnt--;
      if (data[b] < data[a]) std::swap(a, b);
      data[a] += data[b];
      data[b] = a;
    }
    return a != b;
  }
  bool same(int a, int b){ return root(a) == root(b); }
  int root(int a){ return data[a] >= 0 ? data[a] = root(data[a]) : a; }
  int size(int a){ return -data[root(a)]; }
  int count(){ return cnt; }
};
//}}}
//{{{ UF2d merge, same, size, count
struct UF2d {
  UF uf;
  const int W, H;
  UF2d(int w, int h) : uf(w * h), W(w), H(h) {}
  bool merge(int ax, int ay, int bx, int by){ return uf.merge(ay * W + ax, by * W + bx); }
  bool same(int ax, int ay, int bx, int by){ return uf.same(ay * W + ax, by * W + bx); }
  int size(int x, int y){ return uf.size(y * W + x); }
  int count(){ return uf.count(); }
};
//}}}
}
}
#endif
//}}}

using namespace std;
using namespace orislib;
using namespace orislib::ds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> duo;
typedef priority_queue<Edge> PQE;
//{{{ templates
#define TT_ template<typename T>inline
#define TTF_ template<typename T,typename F>inline
TT_ T sq(T x){return x*x;}
TT_ T In(){T x;cin>>x;return x;}
TT_ void sort(T&v){sort(v.begin(),v.end());}
TT_ void revs(T&v){reverse(v.begin(),v.end());}
TT_ void uniq(T&v){sort(v);v.erase(unique(v.begin(),v.end()),v.end());}
TT_ void inpt(T&v,int n){for(v.reserve(n);n--;){typename T::value_type x;cin>>x;v.push_back(x);}}
TT_ void show(T& v,string d=" ",string e="\n"){for(int i=0,i_=v.size();i<i_;++i)cout<<v[i]<<((i==i_-1)?e:d);}
TTF_ int ubnd(T&v,F&x){return upper_bound(v.begin(),v.end(),x)-v.begin();}
TTF_ int lbnd(T&v,F&x){return lower_bound(v.begin(),v.end(),x)-v.begin();}

inline void fast_io(){ios::sync_with_stdio(0);cin.tie(0);}
inline int in(){int x;scanf("%d",&x);return x;}
inline ll pow_mod(ll a,ll k,ll m){ll r=1;for(;k>0;a=a*a%m,k>>=1)if(k&1)r=r*a%m;return r;}
inline ll mod_inv(ll a,ll p){return pow_mod(a,p-2,p);}
inline int puts(const string&s){ return puts(s.c_str()); }
//}}} priority_queue queue deque first second front  stringstream max_element min_element insert
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int Mod = 1000000000 + 0;
const int MAX_N = 100000;

Graph G(MAX_N);
Edges V;

ll ans[MAX_N * 2], pCost[MAX_N], cost;
int ord[MAX_N], dst[MAX_N], low[MAX_N], id[MAX_N];
bool vis[MAX_N];
PQE pool[MAX_N];

void predfs(int u, int p, int &k) {
  ord[u] = low[u] = k++;
  vis[u] = true;
  for (const auto& e : G[u]){
    if (!vis[e.to] && V[e.id].inMST){
      predfs(e.to, u, k);
      low[u] = min(low[u], low[e.to]);
    }
    else if (e.to != p){
      low[u] = min(low[u], ord[e.to]);
    }
  }
  dst[u] = k++;
}

inline void merge_pqe(PQE*& a, PQE*& b){
  if (a->size() < b->size()) swap(a, b);
  while (!b->empty()){
    a->push(b->top());
    b->pop();
  }
}

PQE* dfs(int u, int p)
{
  PQE* pp = &pool[u];
  for (int i = 0; i < G[u].size(); i++){
    Edge& e = G[u][i];
    if (e.to != p && V[e.id].inMST){
      pCost[e.to] = e.w;
      id[e.to] = e.id;
      PQE* qq = dfs(e.to, u);
      merge_pqe(pp, qq);
    }
    else if (e.to != p && !(ord[u] <= ord[e.to] && dst[e.to] <= dst[u])){
      pp->push(e);
    }
  }
  while (!pp->empty() && ord[u] <= ord[pp->top().to] && dst[pp->top().to] <= dst[u]){
    pp->pop();
  }
  if (~p){
    if (pp->empty()) ans[id[u]] = -1;
    else ans[id[u]] = cost - pCost[u] + pp->top().w;
  }
  return pp;
}

struct Data {
  PQE* pq;
  int u, p, i;
  Data(PQE* pq, int u, int p, int i) : pq(pq), u(u), p(p), i(i) {}
};

inline PQE* inline_dfs(int u_, int p_)
{
  stack<Data> st;
  st.push(Data(&pool[u_], u_, p_, 0));
  while (!st.empty()){
    bool add = false;
    PQE*& pp = st.top().pq;
    int u = st.top().u;
    int p = st.top().p;
    for (int& i = st.top().i; i < G[u].size(); i++){
      Edge& e = G[u][i];
      if (e.to != p && V[e.id].inMST){
        pCost[e.to] = e.w;
        id[e.to] = e.id;
        add = true;
        i++;
        st.push(Data(&pool[e.to], e.to, u, 0));
        break;
      }
      else if (e.to != p && !(ord[u] <= ord[e.to] && dst[e.to] <= dst[u])){
        pp->push(e);
      }
    }
    if (!add){
      while (!pp->empty() && ord[u] <= ord[pp->top().to] && dst[pp->top().to] <= dst[u]){
        pp->pop();
      }
      if (~p){
        if (pp->empty()) ans[id[u]] = -1;
        else ans[id[u]] = cost - pCost[u] + pp->top().w;
      }
      if (st.size() == 1u) break;
      PQE* q = st.top().pq;
      st.pop();
      merge_pqe(st.top().pq, q);
    }
  }
  return st.top().pq;
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    a = in() - 1, b = in() - 1, w = in();
    G[a].emplace_back(-1, b, w, i);
    G[b].emplace_back(-1, a, w, i);
    V.emplace_back(a, b, w, i);
  }

  // {{{ Kruskal
  sort(V);
  revs(V);
  UF uf(MAX_N);
  int ecnt = 0;
  for (const auto& e : V){
    if (!uf.same(e.from, e.to)){
      uf.merge(e.from, e.to);
      cost += e.w;
      V[e.id].inMST = true;
      ecnt++;
    }
  }
  // }}}
  if (ecnt != n - 1){
    for (int i = 0; i < m; i++) puts("-1");
  }
  else {
    for (int i = 0; i < m; i++) {
      if (!V[i].inMST) ans[i] = cost;
    }
    int k = 0;
    predfs(0, -1, k);
    inline_dfs(0, -1);
    for (int i = 0; i < m; i++) {
      printf("%lld\n", ans[i]);
    }
  }
  return (0);
}