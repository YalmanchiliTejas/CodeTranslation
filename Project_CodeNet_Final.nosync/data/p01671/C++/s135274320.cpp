#include <bits/stdc++.h>
#define int long long
#define M 200005
using namespace std;

class UF{
public:
  int V;
  vector<int> par,rnk,sz;
  UF(){}
  UF(int V):V(V),par(V),rnk(V,0),sz(V,1){for(int i=0;i<V;i++)par[i]=i;}
  
  int find(int x){
    assert(x < V);
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
  }
  
  void unite(int x,int y){
    x=find(x), y=find(y);
    if(x==y)return;
    if(rnk[x]<rnk[y])par[x]=y, sz[y] += sz[x];
    else{
      par[y]=x;
      sz[x] += sz[y];
      if(rnk[x]==rnk[y])rnk[x]++;
    }
  }

  bool same(int x,int y){return find(x)==find(y);}

  int size(int x){return sz[find(x)];}
};

class RMQ{
public : 
  typedef pair<int,int> P;
  typedef long long ll;
  const ll INF = 1LL<<55;
  struct data{
    bool type; //0 - empty   , 1 - update
    ll value;
  };
  ll n;
  vector<ll> dat;
  vector<data> td;
  
  RMQ(){n=-1;}
  RMQ(int n_){
    n=1;
    while(n<n_)n*=2;
    td.resize(2*n-1,(data){0,0});
    dat.resize(2*n-1,INF);
  }
  
  //[a,b)の値をxに変更　update(a,b,x)
  ll update(int a,int b,int x,bool flg=true,int k=0,int l=0,int r=-1){
    if(r==-1) r=n, assert(a < n && b <= n);
    if(r<=a||b<=l)return flg? dat[k]:INF;
    if(a<=l&&r<=b){
      if(flg==true){
        td[k]=(data){1,x};
        dat[k]=x;
      }
      return dat[k];
    }
    
    if(td[k].type){
      dat[k*2+1]=dat[k*2+2]=td[k].value;
      td[k*2+1]=td[k*2+2]=(data){1,td[k].value};
      td[k].type=0;
    }
    
    ll vl=update(a,b,x,flg,k*2+1,l,(l+r)/2);
    ll vr=update(a,b,x,flg,k*2+2,(l+r)/2,r);
    if(flg==true)dat[k]=min(vl,vr);
    return min(vl,vr);
  }
  
  //[a,b)の最小値を得る　find(a,b);
  ll find(int a,int b){return update(a,b,0,false);};
};

class HLD{
public:
  int V;                     //ノード数
  int root;                  //根の頂点番号
  vector<vector<int> > G;    //Grapth
  vector<int> par;           //parent: par[元の頂点番号]->元の頂点番号
  vector<int> Hchild;        //各ノードから伸びるHeavy Childの頂点番号: Hedge[元の頂点番号]->元の頂点番号
  vector<int> number;        //各ノードに割り当てなおした頂点番号: number[元の頂点番号]->振り直した頂点番号
  vector<int> id;            //割り当て直した数字の元のノード番号: id[振り直した頂点番号]->元の頂点番号
  vector<int> group;         //各ノードが所属するグループ番号: group[元の頂点番号]->元の頂点番号
  vector<int> depth;         //根からの各ノードの深さ: depth[元の頂点番号]
  bool ok;                   //build()が済んでいるか
  
  HLD(){root = V = -1;}
  HLD(int V):V(V), root(0), G(V), par(V,-1), Hchild(V,-1), 
             number(V,-1),id(V,-1),group(V,-1),depth(V,0),ok(false){}
  
  void add_edge(int a,int b){
    assert(a < V && b < V);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  void build(int _root = 0){
    root = _root;
    int num = 0;
    ok = true;
    dfs1(); numbering(num); dfs2();
  }

  int dfs1(int pos = -1,int pre = -1){
    if(pos == -1) pos = root;
    int mx = -1, weight = 1;
    for(int to:G[pos]){
      if(to == pre) continue;
      int cweight = dfs1(to,pos);
      weight += cweight;
      if(mx < cweight) Hchild[pos] = to, mx = cweight;
    }
    return weight;
  }
  
  void dfs2(int pos = -1,int pre = -1,int dep = 0,int g = -1){
    if(pos == -1) pos = g = root;
    par[pos] = pre;
    depth[pos] = dep;
    group[pos] = g;
    for(int to:G[pos]) if(to!=pre) dfs2(to,pos,dep+1,Hchild[pos]==to? g:to);
  }
  
  void numbering(int &cnt,int pos = -1,int pre = -1){
    if(pos == -1) pos = root;
    number[pos] = cnt++;
    id[number[pos]] = pos;
    if(Hchild[pos]>=0) numbering(cnt,Hchild[pos],pos);
    for(int to:G[pos])if(to!=pre && to!=Hchild[pos]) numbering(cnt,to,pos);
  }
  
  typedef pair<int,int> P;
  vector<P> paths;  //[u,v]間の経路をいくつかの「閉区間の連番の経路」に分解する。(最大logN個に分解される)
  vector<P> Ledges; //paths同士を結ぶライトエッジ
  void buildPaths(int u,int v){
    if(depth[group[u]] < depth[group[v]]) swap(u,v);// 深い方のノードから処理する。
    int nu=number[u], nv=number[v];
    if(same(u,v)){ paths.push_back(P(min(nu,nv),max(nu,nv)));return;} 

    int gu = group[u];
    buildPaths(par[gu],v);

    paths.push_back(P(number[gu], number[u]));
    Ledges.push_back(P(number[par[gu]], number[gu]));
  }
  
  pair<vector<P>, vector<P> > getPath(int u,int v){
    assert(ok && "Please Build");
    paths.clear();
    Ledges.clear();
    buildPaths(u,v);
    return make_pair(paths,Ledges);
  }
  
  /*(元の頂点番号,元の頂点番号)*/ 
  bool same(int a,int b){return group[a] == group[b];}
};

typedef pair<int,int> P;
typedef pair<P,P> P1;
typedef pair<vector<P>,vector<P> > P2;
typedef pair<int,P> P3;
const int INF = 1LL<<55;

int n, m, a[M], b[M], w[M], used[M];

void solve(){
  
  vector<P1> v;
  
  for(int i=0;i<m;i++) v.push_back(P1(P(w[i],i),P(a[i],b[i])));
  
  sort(v.begin(), v.end());
  
  UF uf = UF(n);
  int mst = 0;

  HLD hld = HLD(n);
    
  for(int i=0;i<v.size();i++){
    
    int cost = v[i].first.first;
    int idx = v[i].first.second;
    int A = v[i].second.first;
    int B = v[i].second.second;

    if(uf.same(A, B)) continue;
    
    used[idx] = 1;    
    uf.unite(A, B);
    
    hld.add_edge(A, B);
    
    mst += cost;
  }
  
  hld.build();
    
  priority_queue<P3> q;
  
  for(int i=0;i<m;i++)
    
    if(!used[i]) q.push(P3(w[i],P(a[i],b[i])));
  
  RMQ rmq = RMQ(n);
  
  while(!q.empty()){

    P3 tmp = q.top(); q.pop();
    
    int cost = tmp.first;
    int A = tmp.second.first;
    int B = tmp.second.second;
    
    P2 t = hld.getPath(A, B);
    
    vector<P> p = t.first;
    vector<P> le = t.second;
    
    for(int i=0;i<p.size();i++){
      
      int s = p[i].first + 1;
      int t = p[i].second;
      
      if(s>t) continue;
      
      rmq.update( s, t + 1, cost );
    }
    
    for(int i=0;i<le.size();i++)
      rmq.update( le[i].second, le[i].second + 1, cost );
    
  }
  
  for(int i=0;i<m;i++){
    
    if(!used[i]) cout<<mst<<endl;
    else{
      
      P2 t = hld.getPath(a[i], b[i]);
      
      vector<P> p = t.first;
      vector<P> le = t.second;
      
      int mincost = INF;

      for(int i=0;i<p.size();i++){
	
	int s = p[i].first + 1;
	int t = p[i].second;
	
	if(s>t) continue;
	
	mincost = min( mincost, rmq.find( s, t + 1 ) );
      }
      
      for(int i=0;i<le.size();i++)
	mincost = min( mincost, rmq.find( le[i].second, le[i].second + 1 ) );

      if( mincost == INF ) cout<<-1<<endl;
      else cout<< mst - w[i] + mincost <<endl;
    }
    
  }
  
}

signed main(){
  
  cin>>n>>m;
  
  for(int i=0;i<m;i++){
    cin>>a[i]>>b[i]>>w[i];
    a[i]--, b[i]--;
  }
  
  solve();
  
  return 0;
}

