#include<bits/stdc++.h>
using namespace std;
using Int = long long;


struct HLDecomposition {
  Int n,pos;
  vector<vector<Int> > G;
  vector<Int> vid, head, sub, hvy, par, dep, inv, type;
  
  HLDecomposition(){}
  HLDecomposition(Int sz):
    n(sz),pos(0),G(n),
    vid(n,-1),head(n),sub(n,1),hvy(n,-1),
    par(n),dep(n),inv(n),type(n){}
  
  void add_edge(Int u, Int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void build(vector<Int> rs={0}) {
    Int c=0;
    for(Int r:rs){
      dfs(r);
      bfs(r, c++);
    }
  }
  
  void dfs(Int rt) {
    using T = pair<Int, Int>;
    stack<T> st;
    par[rt]=-1;
    dep[rt]=0;
    st.emplace(rt,0);
    while(!st.empty()){
      Int v=st.top().first;
      Int &i=st.top().second;
      if(i<(Int)G[v].size()){
	Int u=G[v][i++];
	if(u==par[v]) continue;
	par[u]=v;
	dep[u]=dep[v]+1;
	st.emplace(u,0);
      }else{
	st.pop();
	Int res=0;
	for(Int u:G[v]){
	  if(u==par[v]) continue;
	  sub[v]+=sub[u];
	  if(res<sub[u]) res=sub[u],hvy[v]=u;
	}
      }
    }
  }

  void bfs(Int r,Int c) {
    Int &k=pos;
    queue<Int> q({r});
    while(!q.empty()){
      Int h=q.front();q.pop();
      for(Int i=h;i!=-1;i=hvy[i]) {
	type[i]=c;
	vid[i]=k++;
	inv[vid[i]]=i;
	head[i]=h;
	for(Int j:G[i])
	  if(j!=par[i]&&j!=hvy[i]) q.push(j);
      }
    }
  }
  
  // for_each(vertex)
  // [l,r] <- attention!!
  void for_each(Int u, Int v, const function<void(Int, Int)>& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]);
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
  }
  
  // for_each(edge)
  // [l,r] <- attention!!
  void for_each_edge(Int u, Int v, const function<void(Int, Int)>& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
	f(vid[head[v]],vid[v]);
        v=par[head[v]];
      } else{
	if(u!=v) f(vid[u]+1,vid[v]);
	break;
      }
    }
  }

  Int lca(Int u,Int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }

  Int distance(Int u,Int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};


template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,E)> G;
  typedef function<T(E,E)> H;
  Int n;
  G g;
  H h;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(){};
  SegmentTree(Int n_,G g,H h,T d1,E d0,
	      vector<T> v=vector<T>()):
    g(g),h(h),d1(d1),d0(d0){
    init(n_);
    if(n_==(Int)v.size()) build(n_,v);
  }
  void init(Int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(n,d1);
    laz.clear();
    laz.resize(2*n-1,d0);
  }
  void build(Int n_, vector<T> v){
    for(Int i=0;i<n_;i++) dat[i]=v[i];
  }
  void update(Int a,Int b,E x,Int k,Int l,Int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x);
      return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
  }
  void update(Int a,Int b,E x){
    update(a,b,x,0,0,n);
  }
  T query(Int k){
    T c=dat[k];
    k+=n-1;
    E x=laz[k];
    while(k>0){
      k=(k-1)/2;
      x=h(x,laz[k]);
    }
    return g(c,x);
  }
};


struct Kruskal{

  struct UnionFind{
    Int n;
    vector<Int> r,p;
    UnionFind(){}
    UnionFind(Int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
    Int find(Int x){
      return (x==p[x]?x:p[x]=find(p[x]));
    }
    bool same(Int x,Int y){
      return find(x)==find(y);
    }
    void unite(Int x,Int y){
      x=find(x);y=find(y);
      if(x==y) return;
      if(r[x]<r[y]) swap(x,y);
      r[x]+=r[y];
      p[y]=x;
    }
  };
  
  struct edge{
    Int from,to,cost,used;
    edge(){}
    edge(Int from,Int to,Int cost):from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };

  Int n;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(Int sz):n(sz){}
  
  void add_edge(Int u,Int v,Int c){
    edges.push_back(edge(u,v,c));
  }

  void input(Int m,Int offset=0){
    Int a,b,c;
    for(Int i=0;i<m;i++){
      cin>>a>>b>>c;
      add_edge(a+offset,b+offset,c);
    }
  }
  
  vector<edge> build(){
    sort(edges.begin(),edges.end());
    UnionFind uf(n+1);
    Int res=0;
    Int cnt=0;
    for(Int i=0;i<(Int)edges.size();i++){
      edge &e=edges[i];
      if(!uf.same(e.from,e.to)){
	res+=e.cost;
	e.used=1;
	uf.unite(e.from,e.to);
	cnt++;
      }
    }
    if(cnt!=n-1){
      for(Int i=0;i<(Int)edges.size();i++) cout<<-1<<endl;
      exit(0);
    }
    return edges;
  }
};



signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> a(m),b(m),w(m);
  for(Int i=0;i<m;i++) cin>>a[i]>>b[i]>>w[i];
  Kruskal mst(n);
  for(Int i=0;i<m;i++){
    a[i]--;b[i]--;
    mst.add_edge(a[i],b[i],w[i]);
  }
  auto es=mst.build();

  Int base=0;
  HLDecomposition hld(n);
  for(Int i=0;i<m;i++){
    if(!es[i].used) continue;
    hld.add_edge(es[i].from,es[i].to);
    base+=es[i].cost;
  }
  hld.build();
  
  const Int INF = 1e9;
  auto g=[](Int a,Int b){return min(a,b);};
  SegmentTree<Int, Int> seg(n,g,g,INF,INF);

  for(Int i=0;i<m;i++){
    if(es[i].used) continue;
    hld.for_each_edge(es[i].from,es[i].to,
		      [&](Int l,Int r){
			seg.update(l,r+1,es[i].cost);
		      });
  }

  //cout<<base<<endl;
  
  auto dep=hld.dep;
  auto par=hld.par;
  auto vid=hld.vid;
  for(Int i=0;i<m;i++){
    Int u=a[i],v=b[i];
    if(dep[u]>dep[v]) swap(u,v);
    if(u!=par[v]) cout<<base<<endl;
    else{
      Int x=seg.query(vid[v]);
      cout<<(x==INF?-1:base-w[i]+x)<<endl;
    }
  }
  
  return 0;
}