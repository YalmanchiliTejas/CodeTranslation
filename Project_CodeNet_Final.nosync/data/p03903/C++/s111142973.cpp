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
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ull INF = ULLONG_MAX;
const ll MOD = 998244353;

typedef ll Weight;
struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

pair<Weight, Edges> Prim(const Graph &g, int r = 0) {
	int n = g.size();
	Edges T;
	Weight total = 0;
	vector<bool> visited(n);
	priority_queue<Edge> Q;
	Q.push(Edge(-1, r, 0));
	while (!Q.empty()) {
		Edge e = Q.top();
		Q.pop();
		if (visited[e.dst])
			continue;
		if(e.src!=-1)T.push_back(e);
		total += e.weight;
		visited[e.dst] = true;
		for (__typeof(g[e.dst].begin()) f = g[e.dst].begin();
				f != g[e.dst].end(); f++)
			if (!visited[f->dst])
				Q.push(*f);
	}
	return pair<Weight, Edges>(total, T);
}

struct HLDecomposition{
  int V;
  vector<vint> g;
  vint dep,par,head,size,inv;
  vint in,out;
  int t;
  HLDecomposition(int size_)
  :V(size_),g(V),dep(V,0),par(V,-1),head(V),size(V),inv(V),in(V),out(V),t(0){}

  void add_edge(int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);
  }

  void dfs_size(int v=0){
    size[v]=1;
    for(int& u:g[v]){
      if(par[u]>=0)continue;
      par[u]=v;
      dfs_size(u);
      size[v]+=size[u];
      if(size[u]>size[g[v][0]]){
        swap(u,g[v][0]);
      }
    }
  }
  void dfs_hld(int v=0){
    in[v] = t++;
    inv[in[v]]=v;
    for(int& u:g[v]){
      if(par[u]!=v)continue;
      head[u]=(u==g[v][0]?head[v]:u);
      dfs_hld(u);
    }
    out[v]=t;
  }

  void build(int root=0){
    par[root]=0;
    dfs_size(root);
    par[root]=-1;
    dfs_hld(root);
  }

  int lca(int u,int v){
    while(1){
      if(in[u]>in[v])swap(u,v);
      if(head[u]==head[v])return u;
      v=par[head[v]];
    }
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};


inline int get_min2pow(int n) {
	int res = 1;
	while (res < n)
		res *= 2;
	return res;
}

///Segment Tree////////

template<typename T,T dval>
struct segtree {
	int N;
	vector<T> node;
	//例外値　ex)INF,0
	T default_value = dval;
	static inline T merge(const T& l, const T& r) {
		//RMQ
		return max(l,r);
		//RSQ
		//return l+r;
	}
	segtree(int n) {
		N = get_min2pow(n);
		node.resize(2 * N, default_value);
	}
	segtree(vector<int> v) {
		int sz = v.size();
		N = get_min2pow(sz);
		node.resize(2 * N, default_value);
		for (int i = 0; i < sz; i++)
			node[i + N - 1] = v[i];
		for (int i = N - 2; i >= 0; i--)
			node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
	}
	// update k th element
	void update(int k, T val) {
		k += N - 1; // leaf
		node[k] = val;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = merge(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	// [a, b)
	T query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
	T query(int a, int b, int k, int l, int r) {
		if (r <= a or b <= l)
			return default_value;
		if (a <= l and r <= b)
			return node[k];
		int m = (l + r) / 2;
		T vl = query(a, b, k * 2 + 1, l, m);
		T vr = query(a, b, k * 2 + 2, m, r);
		return merge(vl, vr);
	}
};



int main(){
  int N,M;cin>>N>>M;
  Graph g(N);
  repeat(i,M){
    int a,b;Weight c;
    cin>>a>>b>>c;
    a--;b--;
    g[a].push_back({a,b,c});
    g[b].push_back({b,a,c});
  }
  Weight total;
  Edges tree;
  tie(total,tree)=Prim(g);
  HLDecomposition hld(N);
  repeat(i,tree.size()){
    hld.add_edge(tree[i].src,tree[i].dst);
  }
  hld.build();
  segtree<ll,0> RMQ(N);
  repeat(i,tree.size()){
    if(hld.in[tree[i].src]>hld.in[tree[i].dst])swap(tree[i].src,tree[i].dst);
    RMQ.update(hld.in[tree[i].dst],tree[i].weight);
  }
  int Q;cin>>Q;
  repeat(q,Q){
    int s,t;cin>>s>>t;s--;t--;
    ll mx=0;
    while(1){
      if(hld.in[s]>hld.in[t])swap(s,t);
      if(hld.head[s]!=hld.head[t]){
        mx = max(mx,RMQ.query(hld.in[hld.head[t]],hld.in[t]+1));
        t=hld.par[hld.head[t]];
      }else{
        if(s!=t)mx = max(mx,RMQ.query(hld.in[s]+1,hld.in[t]+1));
        break;
      }
    }
    cout << total-mx<<endl;
  }
  return 0;
}
