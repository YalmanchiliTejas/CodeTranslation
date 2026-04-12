#include<bits/stdc++.h>
using namespace std;

const int MAX = (1<<18);
const int INF = (1<<29);
typedef long long ll;

struct seg{
  int d[MAX];
  int n;
  void init(int _n){
    memset(d,0,sizeof(d));
    n=1; while( n < _n ) n*=2;
  }
  void add(int a,int b,int k,int l,int r,int x){
    if( b <= l || r <= a ) {}
    else if( a <= l && r <= b ) d[k]+=x;
    else {
      add( a, b, 2*k+1, l, (l+r)/2, x );
      add( a, b, 2*k+2, (l+r)/2, r, x );
    }
  }
  int get(int k){
    k += n-1;
    int ret = d[k];
    while( k > 0 ){
      k = (k-1)/2;
      ret += d[k];
    }
    return ret;
  }

  void add(int a,int b,int x){
    add( a, b, 0, 0, n, x );
  }  
};

struct seg2{
  int d[MAX];
  int n;
  void init(int _n){
    n=1; while( n < _n ) n*=2;
    fill( d, d+2*n, INF );
  }
  void update(int a,int b,int k,int l,int r,int x){
    if( b <= l || r <= a ) {}
    else if( a <= l && r <= b ) d[k]=min( d[k],x );
    else {
      update( a, b, 2*k+1, l, (l+r)/2, x );
      update( a, b, 2*k+2, (l+r)/2, r, x );
    }
  }
  int get(int k){
    k += n-1;
    int ret = d[k];
    while( k > 0 ){
      k = (k-1)/2;
      ret = min( ret, d[k] );
    }
    return ret;
  }

  void update(int a,int b,int x){
    update( a, b, 0, 0, n, x );
  }  
};

struct edge{
  int u,v,w,id;
  bool operator<(const edge& e ) const {
    return w < e.w;
  }
};

struct uni{
  int d[100005];
  void init(){ memset(d,-1,sizeof(d) ); }
  int find(int a){ return d[a]<0?a:(d[a]=find(d[a])); }
  void merge(int a,int b){
    a = find(a); b = find(b);
    if( a == b ) return;
    if( d[a]>d[b]) swap(a,b);
    d[a]+=d[b]; d[b] = a;
  }
  bool same(int a,int b){ return find(a)==find(b); }
  int size(){ return -d[find(0)]; }
};

seg S;
seg2 HLS;
int N,M;
vector<int> G[100005];
vector<edge> E;
ll ans;
vector<int> T[100005];

//?????????????????¢???????????????
vector<int> vs;
//Heavy-Edge???????????????
vector<int> hs;
//Light-Edge??????
vector<int> ps;
//??¨?????¨????????????
vector<int> sz;


int edgeTo(int u,int id,vector<int>& g){
  if( E[g[id]].u == u ) return E[g[id]].v;
  return E[g[id]].u;
}

int vsize(int v,int pr){
  int er=-1;
  sz[v] = 1;
  pair<int,int> maxi={-1,0};
  for(int i=0;i<(int)T[v].size();i++){
    int to = edgeTo(v,i,T[v]);
    if( to == pr )
      er = i;
    else{
      sz[v] += vsize( to, v);
      maxi = max( maxi, make_pair(sz[to],i) );
    }
  }
  if( er>=0 )
    T[v].erase(T[v].begin()+er);
  if( maxi.first != -1 ){
    //cout << maxi.first << " "<<maxi.second << endl;
    if( er>=0 && er < maxi.second ) maxi.second--;
    int nt = T[v][maxi.second];
    T[v].erase(T[v].begin()+maxi.second);
    T[v].insert(T[v].begin(), nt );
  }
  return sz[v];
}

void dfs(int v,int pr,bool hvf,int &t){
  vs[v] = t++;
  if( hvf ){
    hs[v] = pr;
    ps[v] = ps[pr];
  } else {
    hs[v] = v;
    ps[v] = pr;
  }
  //cout << "dfs " << v << " " << pr << " "<< hvf << endl;
  //cout << hs[v] << " " << ps[v] << endl;
  for(int i=0;i<(int)T[v].size();i++){
    int to = edgeTo(v,i,T[v]);
    if( i == 0 )
      dfs( to, hs[v],true, t );
    else 
      dfs( to, v,false, t );    
  }  
}

bool maketree(){
  ans = 0;
  uni U; U.init();
  sort(E.begin(),E.end());
  for(int i=0;i<M;i++){
    int u = E[i].u, v = E[i].v;

    //cout <<i <<": " << u << " " << v << " " << E[i].w << endl;
    
    G[u].push_back( i );
    G[v].push_back( i );
    if( U.same( u, v ) ) continue;
    U.merge( u, v );
    T[u].push_back( i );
    T[v].push_back( i );
    ans+=(ll)E[i].w;
  }
  
  if( U.size() != N ) return false;

  vs = vector<int>(N);
  hs = vector<int>(N);
  ps = vector<int>(N);
  sz = vector<int>(N);
  int t =0;
  vsize(0,-1);
  dfs( 0, -1,false, t );
  return true;
}


void query(int v,int k,int w){
  int now = vs[v];
  int low = vs[hs[v]];
  //cout << "query: " << v << " " << k << " " << w << endl;
  //cout << now << " " << low << endl;
  //cout << "[ " << low << ", " << now+1 << " )" << endl;
  
  if( now - low + 1 < k ){//??????
    query(ps[v],k-(now-low+1),w);
  }
  low = max( vs[hs[v]], now-k+1 );
  HLS.update(low,now+1,w);
}


ll res[200002];

void solve(int v,int e,int r){
  for(int i=0;i<(int)T[v].size();i++){
    int to = edgeTo(v,i,T[v]);
    int pr;
    int pl = vs[to];
    if( i == (int)T[v].size()-1 ) pr = r;
    else pr = vs[edgeTo(v,i+1,T[v])];
    //cout << v << " - " << e << " - " << r << endl;
    //cout << "[ "<< 0 << ", " << pl <<" ) [ "<< pr << ", " << N << " )" << endl;
    S.add( 0,pl, 1 );
    S.add( pr,N, 1 );
    solve( to, T[v][i], pr );
    S.add( 0,pl, -1);
    S.add( pr,N, -1);
  }
  
  //cout << "solve: " << v << " " << e << " "<< r << endl;
  if( e != -1 ){
    for(int i=0;i<(int)G[v].size();i++){
      if( G[v][i] == e ) continue;
      int to = edgeTo( v, i, G[v] );      
      //cout<<"-> " <<to << " "<< S.get(vs[to]) << endl;
      int k = S.get(vs[to]);
      if( k ) 
        query( v, k, E[G[v][i]].w );       
    }
    int st = HLS.get( vs[v] );
    //cout << e << " "<< E[e].id << " ( "<< E[e].w << " or " << st << " ) " << INF << endl;
    //cout << ans << " "<< res[E[e].id] << endl;
    if( st == INF ) res[E[e].id] = -1;
    else res[E[e].id] = ans - (ll)E[e].w + (ll)st;
  }
  
}

void solve(){
  solve(0,-1, N);
}


int main(){
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int u,v,w; cin >> u >> v >> w;
    u--; v--;
    E.push_back( {u,v,w,i} );
  }

  if( maketree() ){
    S.init(N);
    HLS.init(N);
    fill(res,res+M,ans);
    solve();
    for(int i=0;i<M;i++){
      cout << res[i] << endl;
    }
  } else {
    for(int i=0;i<M;i++)
      cout << -1 << endl;
  }
}