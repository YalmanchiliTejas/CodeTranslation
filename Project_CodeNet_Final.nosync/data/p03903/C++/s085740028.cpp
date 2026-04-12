#include <bits/stdc++.h>
#define LLI long long int
#define FOR(v, a, b) for(LLI v = (a); v < (b); ++v)
#define FORE(v, a, b) for(LLI v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(LLI v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define fst first
#define snd second
#define popcount __builtin_popcount
#define UNIQ(v) (v).erase(unique(ALL(v)), (v).end())
#define bit(i) (1LL<<(i))

#ifdef DEBUG
#include <misc/C++/Debug.cpp>
#else
#define dump(...) ((void)0)
#endif

#define gcd __gcd

using namespace std;
template <class T> constexpr T lcm(T m, T n){return m/gcd(m,n)*n;}

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}

template <typename T, typename U> bool chmin(T &a, const U &b){return (a>b ? a=b, true : false);}
template <typename T, typename U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}

template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}

  Edge rev() const {return Edge(to,from,cost);}
  
  friend ostream& operator<<(ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = vector<vector<Edge<T>>>;
template <typename T> using Tree = vector<vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].push_back(Edge<T>(from, to, w));  
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  g[a].push_back(Edge<T>(a, b, w));
  g[b].push_back(Edge<T>(b, a, w));
}

class UnionFind{
  vector<int> parent, depth, size;
  int count;
public:
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    iota(ALL(parent),0);
  }
  int get_root(int i){
    if(parent[i] == i) return i;
    else return parent[i] = get_root(parent[i]);
  }
  bool is_same(int i, int j){return get_root(i) == get_root(j);}
  int merge(int i, int j){
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }
  int get_size(int i){return size[get_root(i)];}
  int count_group(){return count;}
};


template <typename T>
vector<tuple<int,int,T>> kruskal(int n, vector<tuple<int,int,T>> &graph){
  sort(graph.begin(), graph.end(), [](tuple<int,int,T> &a, tuple<int,int,T> &b){return get<2>(a) < get<2>(b);});
  UnionFind uf(n);
  vector<tuple<int,int,T>> mst;
  for(auto v : graph){
    int s,t,d;
    tie(s,t,d) = v;
    if(!uf.is_same(s,t)){
      uf.merge(s,t);
      mst.push_back(v);
    }
  }
  return mst;
}

template <typename T> class HLDecomposition{
  Tree<T> tree;
  int n;

  vector<int> sub, par, head, id, rid, next, end;

  int dfs_sub(int cur, int p){
    par[cur] = p;
    int t = 0;
    for(auto &e : tree[cur]){
      if(e.to == p) continue;
      sub[cur] += dfs_sub(e.to, cur);
      if(sub[e.to] > t){
        t = sub[e.to];
        next[cur] = e.to;
        swap(e, tree[cur][0]);
      }
    }
    return sub[cur];
  }

  void dfs_build(int cur, int &i){
    id[cur] = i;
    rid[i] = cur;
    ++i;

    for(auto &e : tree[cur]){
      if(e.to == par[cur]) continue;
      head[e.to] = (e.to == tree[cur][0].to ? head[cur] : e.to);
      dfs_build(e.to, i);
    }

    end[cur] = i;
  }
  

public:
  HLDecomposition(const Tree<T> &tree):
    tree(tree), n(tree.size()), sub(n,1), par(n,-1), head(n), id(n), rid(n), next(n,-1), end(n, -1){
    dfs_sub(0, -1);
    int i=0;
    dfs_build(0, i);
  }

  void path_query_vertex(int x, int y, const function<void(int,int)> &f){
    while(1){
      if(id[x] > id[y]) swap(x, y);
      f(max(id[head[y]], id[x]), id[y]+1);
      if(head[x] == head[y]) return;
      y = par[head[y]];
    }
  }

  void path_query_edge(int x, int y, const function<void(int,int)> &f){
    while(1){
      if(id[x] > id[y]) swap(x, y);
      if(head[x] == head[y]){
        if(x != y) f(id[x]+1, id[y]+1);
        return;
      }
      f(id[head[y]], id[y]+1);
      y = par[head[y]];
    }
  }

  int parent(int x){return par[x];};

  void subtree_query_edge(int x, const function<void(int,int)> &f){
    f(id[x]+1, end[x]);
  }
};

template <typename T, typename U> class SegmentTreeRangeUpdateQueryRangeMaximumQuery{
  int size;
  vector<T> vec1;
  vector<U> vec2;
  vector<bool> is_updated;
  T e1;

  inline void propagate(int i, int l){
    if(is_updated[i]) return;
    if(i < size/2){
      if(not is_updated[i]){
        vec2[i*2+1] = vec2[i];
        vec2[i*2+2] = vec2[i];

        is_updated[i*2+1] = false;
        is_updated[i*2+2] = false;
      }
    }
    if(not is_updated[i]) vec1[i] = vec2[i];
    is_updated[i] = true;
  }

  inline T update_aux(int i, int l, int r, int s, int t, const U &x){
    propagate(i,r-l);
    if(r <= s || t <= l) return vec1[i];
    else if(s <= l && r <= t){
      vec2[i] = x;
      is_updated[i] = false;
      propagate(i,r-l);
      return vec1[i];
    }
    else return vec1[i] = max(update_aux(i*2+1,l,(l+r)/2,s,t,x), update_aux(i*2+2,(l+r)/2,r,s,t,x));
  }
  
  inline T query_aux(int i, int l, int r, int x, int y){
    propagate(i,r-l);
    if(r <= x || y <= l) return e1;
    else if(x <= l && r <= y) return vec1[i];
    else return max(query_aux(i*2+1,l,(l+r)/2,x,y), query_aux(i*2+2,(l+r)/2,r,x,y));
  }
  
public:
  SegmentTreeRangeUpdateQueryRangeMaximumQuery(int n, const T &e1, const U &init): e1(e1){
    size = 1;
    while(size<n) size*=2;
    size = size*2-1;

    vec1 = vector<T>(size, init);
    vec2 = vector<U>(size, init);
    is_updated = vector<bool>(size, true);
  }

  inline void update(int s, int t, const U &x){
    update_aux(0,0,size/2+1,s,t,x);
  }
  
  inline T get(int x, int y){
    return query_aux(0,0,size/2+1,x,y);
  }
};





int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;
  while(cin >> n >> m){
    vector<tuple<int,int,LLI>> edges;
    REP(i,m){
      int a,b; cin >> a >> b; --a, --b;
      LLI c; cin >> c;
      edges.push_back(make_tuple(a,b,c));
    }

    

    auto es = kruskal(n,edges);
    LLI sum = 0;
    for(auto &e : es) sum += get<2>(e);
    
    Tree<LLI> tree(n);
    for(auto &e : es){
      add_undirected(tree, get<0>(e), get<1>(e), get<2>(e));
    }

    HLDecomposition<LLI> hld(tree);
    SegmentTreeRangeUpdateQueryRangeMaximumQuery<LLI,LLI> seg(n, 0, 0);

    for(auto &e : es){
      hld.path_query_edge(get<0>(e), get<1>(e), [&](int x, int y){seg.update(x,y,get<2>(e));});
    }


    int Q; cin >> Q;
    
    REP(i,Q){
      int s,t; cin >> s >> t; --s, --t;

      LLI ans = sum;

      LLI temp = 0;
      
      auto f = [&](int x, int y){chmax(temp, seg.get(x,y));};
      hld.path_query_edge(s,t,f);
    
      ans -= temp;
      
      cout << ans << endl;
    }
  }
  
  return 0;
}
