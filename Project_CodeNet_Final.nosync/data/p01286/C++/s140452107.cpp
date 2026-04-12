#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3
#define MAX_V 800

struct edge{ int to,cap,rev; };
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void init(){
  rep(i,MAX_V){
    G[i].clear();
  }
}

void add_edge(int from,int to,int cap){
  G[from].push_back((edge){to,cap,(int)G[to].size()});
  G[to].push_back((edge){from,0,(int)G[from].size()-1});
}

void bfs(int s){
  memset(level,-1,sizeof(level));
  queue<int> que;
  level[s]=0;
  que.push(s);
  while(!que.empty()){
    int v=que.front(); que.pop();
    for(int i=0;i<G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[e.to]<0){
        level[e.to]=level[v]+1;
        que.push(e.to);
      }
    }
  }
}

int dfs(int v,int t,int f){
  if(v==t)return f;
  for(int &i=iter[v];i<G[v].size();i++){
    edge &e=G[v][i];
    if(e.cap>0&&level[v]<level[e.to]){
      int d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow=0;
  while(1){
    bfs(s);
    if(level[t]<0)return flow;
    memset(iter,0,sizeof(iter));
    int f;
    while((f=dfs(s,t,INF))>0){
      flow+=f;
    }
  }
}

ll h,w,c,m,nw,nc,nm;

int main(){
	cin.sync_with_stdio(false);
  while(1){
    cin>>h>>w>>c>>m>>nw>>nc>>nm;
    if(h==-1)break;
    init();
    ll hst=0,wst=hst+h*2,cst=wst+w*2+nw*2,mst=cst+c*2+nc*2;
    ll source=mst+m*2+nm*2,sink=source+1;
    rep(i,h){
      add_edge(source,hst+i,1);
      add_edge(hst+i,hst+h+i,1);
      rep(j,nw)add_edge(hst+h+i,wst+w+j,1);
    }
    rep(i,w+nw){
      add_edge(wst+i,wst+w+nw+i,1);
      if(i<w){
        rep(j,nc)add_edge(wst+w+nw+i,cst+c+j,1);
      }else{
        rep(j,c)add_edge(wst+w+nw+i,cst+j,1);
      }
    }
    rep(i,c+nc){
      add_edge(cst+i,cst+c+nc+i,1);
      if(i<c){
        rep(j,nm)add_edge(cst+c+nc+i,mst+m+j,1);
      }else{
        rep(j,m)add_edge(cst+c+nc+i,mst+j,1);
      }
    }
    rep(i,m+nm){
      add_edge(mst+i,mst+m+nm+i,1);
      add_edge(mst+m+nm+i,sink,1);
    }
    rep(i,w){
      ll num;
      cin>>num;
      while(num--){
        ll p;
        cin>>p; p--;
        add_edge(hst+h+p,wst+i,1);
      }
    }
    rep(i,c){
      ll num;
      cin>>num;
      while(num--){
        ll p;
        cin>>p; p--;
        add_edge(wst+w+nw+p,cst+i,1);
      }
    }
    rep(i,m){
      ll num;
      cin>>num;
      while(num--){
        ll p;
        cin>>p; p--;
        add_edge(cst+c+nc+p,mst+i,1);
      }
    }
    cout<<max_flow(source,sink)<<endl;
  }
	return 0;
}