#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_V 100000
typedef pair<ll,int> P;
ll INF=100000000000LL;

struct edge { ll to,cap,cost,rev; };

int V;
vector<edge> G[MAX_V];
ll h[MAX_V];
ll dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void init_edge(){
  for(int i=0;i<V;i++)G[i].clear();
}

void add_edge(int from,int to,int cap,ll cost){
  G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
  G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}

ll min_cost_flow(int s,int t,int f){
  ll res = 0;
  fill(h,h+V,0);
  while(f>0){

    priority_queue< P, vector<P>, greater<P> >  que;
    fill( dist, dist+V , INF );
    dist[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      int v = p.second;
      if(dist[v]<p.first)continue;
      for(int i=0;i<(int)G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap>0&&dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
          dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
          prevv[e.to]=v;
          preve[e.to]=i;
          que.push(P(dist[e.to],e.to));
        }
      }
    }

    if(dist[t]==INF){
      return -1;
    }
    for(int v=0;v<V;v++)h[v]+=dist[v];

    int d=f;
    for(int v=t;v!=s;v=prevv[v]){
      d=min(d,(int)G[prevv[v]][preve[v]].cap);
    }
    f-=d;
    res+=(ll)d*h[t];
    for(int v=t;v!=s;v=prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

int H,W;
int t[200][200];

int main(){
  cin>>H>>W;
  int si=H*W*2;
  int ti=si+1;
  V=ti+1;

  int N=H*W;
  ll mx=1e6;
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>t[i][j];
      add_edge(i*W+j,i*W+j+N,1,mx);
      add_edge(i*W+j,i*W+j+N,1,mx-t[i][j]);
      //      add_edge(i*W+j,i*W+j+N,1,mx);
      if(i+1<H){
        int id=(i+1)*W+j;
        add_edge(i*W+j+N,id,2,0);
      }
      if(j+1<W){
        int id=i*W+(j+1);
        add_edge(i*W+j+N,id,2,0);
      }
      
    }
  }
  add_edge(si, 0, 2, 0);
  add_edge( (H-1)*W+(W-1)+N , ti, 2,0);

  ll ans= min_cost_flow(si,ti,2);
  
  ans-=mx*(H+W-1)*2;
  cout<<-ans<<endl;
  return 0;
}

