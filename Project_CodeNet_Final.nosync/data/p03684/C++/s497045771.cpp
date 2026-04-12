#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define LOOP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define UB upper_bound
#define LB lower_bound
#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;
const double PI=3.141592653589;

struct Edge{
  int src;int dst;int wei;
  Edge(int s=0,int d=0,int w=0):src(s),dst(d),wei(w){}
};
using Graph = vector<vector<Edge>>;

int par[100005];
int rnk[100005];


int root(int x){
  return par[x]==x?x:par[x]=root(par[x]);
}
void unite(int a,int b){
  par[root(a)]=root(b);
}

/*
void init(int n){
  REP(i,n){
    par[i]=i;
    rnk[i]=0;
  }
}

int find(int x){
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return;
  if(rnk[x]<rnk[y])par[x]=y;
  else{
    par[y]=x;
    if(rnk[x]==rnk[y])rnk[x]++;
  }
}
*/


int Kruskal(Graph&g){
    vector<Edge> es;
    REP(i,g.size()){
      REP(j,g[i].size()){
        es.PB(g[i][j]);
      }
    }
    sort(es.begin(),es.end(),[](const Edge&a,const Edge&b){
      return a.wei<b.wei;
    });
    REP(i,g.size())par[i]=i;
    int sum=0;
    REP(i,es.size()){
      if(root(es[i].src)!=root(es[i].dst)){
        sum+=es[i].wei;
        unite(es[i].src,es[i].dst);
      }
    }
    return sum;
}

signed main(){
  int n;
  cin>>n;
  vector<pair<int,int>> vx(n),vy(n);
  int x,y;
  REP(i,n){
    cin>>x>>y;
    vx[i]=MP(x,i);
    vy[i]=MP(y,i);
  }
  sort(ALL(vx));
  sort(ALL(vy));

  Graph g(n);

  REP(i,n-1){
    int sx=vx[i].SEC;int dx=vx[i+1].SEC;
    int sy=vy[i].SEC;int dy=vy[i+1].SEC;
    g[sx].emplace_back(sx,dx,abs(vx[i].FIR-vx[i+1].FIR));
    g[sy].emplace_back(sy,dy,abs(vy[i].FIR-vy[i+1].FIR));
  }
//  init(n);

  cout<<Kruskal(g)<<endl;

  return 0;
}
