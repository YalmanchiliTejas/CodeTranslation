// warm heart, wagging tail,and a smile just for you!
//
//                            ▒█████▒▒
//                             ██████████▒
//                             ▒████████████▒
//                            ██████████████████
//                           ████████████████████▒
//                          ▒██████████████████████▒
//                          ▒███████████████████████
//                      ▒████▒▒▒▒▒▒█████████████████▒
//                    ███▒▒▒▒▒▒██████████████████████▒▒▒
//                  ▒██▒▒███████████████████████▒▒▒▒▒██████
//                 ▒█████████████████████████▒▒▒▒▒▒█████████▒
//                 ▒█████████████████████▒▒▒▒▒▒██████████████
//                  ▒████         ████▒▒▒▒▒████         ████▒
//              ▒█████▒    ████    ▒▒▒▒███████    ████    ██████▒
//            ▒██▒▒▒▒▒    ██████    █████████    ██████    ██▒▒▒██▒
//           █████████   ████████   █████████   ████████   ▒▒▒▒█████
//          ▒█████████    ██████    ████████▒    ██████    █████████
//          ▒██████████    ████    █████▒▒▒▒▒▒    ████    ██████████
//           ████████████        ▒▒▒▒▒▒▒████████        ███████████▒
//       ▒██████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███████████████████████████████████▒
//     ███▒▒▒▒▒▒▒▒▒▒▒▒█████████████████████████████████████████▒▒████████▒
//   ▒▒▒▒▒▒▒▒▒██████████████                         ███████▒▒▒▒███████████
//   █████████████████████████                     ███████▒▒▒██████████████▒
//   █████████████████████████████             ███████▒▒▒██████████████████▒
//   ██████████████████████████████████████████████████████████████████████
//    ██████████████████████████████████████████████████████████████████▒
//      ▒█████████████████▒▒▒▒▒▒▒██████████████████████████████████▒▒▒
//
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int N = 4000;
vector<P> edge[N];
vector<int> dist(N);
int MAX_LOG_V = log2(N)+1;
mat par(MAX_LOG_V,vec(N+1));

void dfs(int no,int p,int d){
  par[0][no]=p;
  dist[no]=d;
  for(auto to:edge[no]){
    if(to.fs!=p) dfs(to.fs,no,d+1);
  }
}

void init(int V, int root){
  dfs(root,-1,0); //root,parent,dist
  for(int k=0;k+1<MAX_LOG_V;++k){
    for(int v=0;v<V;v++){
      if(par[k][v]<0) par[k+1][v]=-1;
      else par[k+1][v]=par[k][par[k][v]];
    }
  }
}

int lca(int u,int v){
  if(dist[u]>dist[v]) swap(u,v);
  for(int k=0;k<MAX_LOG_V;++k){
    if((dist[v]-dist[u])>>k&1){
      v=par[k][v];
    }
  }
  if(u==v) return u;
  for(int k=MAX_LOG_V-1;k>=0;--k){
    if(par[k][u]!=par[k][v]){
      u=par[k][u];
      v=par[k][v];
    }
  }
  return par[0][u];
}

struct UnionFind {
  private:
  vector<int> child,tree,sum;

public:
  UnionFind(int v) {
    tree.resize(v);
    sum.resize(v);
    REP(i,v) tree[i] = i, sum[i] = 1;
  }

  int root(int i){
    if(i == tree[i]){
      REP(j,child.size()) tree[child[j]] = i;
      child.clear(); 
      return i;
    }
    else{
      child.push_back(i);
      return i = root(tree[i]);
    }
  }

  int size(int i){
    return sum[root(i)];
  }

  bool unit(int x, int y){
    x = root(x);
    y = root(y);
    if(x==y) return false;
    sum[min(x,y)] += sum[max(x,y)];
    tree[max(x,y)] = min(x,y);
    return true;
  }

  bool isUnit(int x, int y){
    return root(x) == root(y);
  }
};

mat dp(N,vec(N,0));
int root;
int dfs2(int no, int pare, int mx){
  dp[root][no] = mx;
  for(auto to:edge[no]){
    if(to.fs == pare) continue;
    dfs2(to.fs,no,max(mx,to.sc));
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  using T = tuple<int,int,int>;
  vector<T> a(m);
  REP(i,m){
    int x,y,z;
    cin >> x >> y >> z;
    x--; y--;
    a[i] = T(z,x,y);
  }

  sort(a.begin(),a.end());

  UnionFind uf(n); int sum = 0;
  REP(i,m){
    int x,y,z;
    tie(z,x,y) = a[i];
    if(uf.unit(x,y)){
      edge[x].push_back(P(y,z));
      edge[y].push_back(P(x,z));
      sum += z;
    }
  }

  init(n,0);

  REP(i,n) root = i, dfs2(i,-1,0);

  int q;
  cin >> q;
  REP(_,q){
    int s,t;
    cin >> s >> t;
    s--; t--;
    int no = lca(s,t);
    cout << sum - max(dp[no][s],dp[no][t]) << "\n";
  }

  return 0;
}