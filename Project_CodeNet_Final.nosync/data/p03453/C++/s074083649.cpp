#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N,M;
int S,T;

vector<tuple<int,int,ll>> edges;
vector<pair<int,ll>> g[100010];
ll dist[2][100010];
const ll INF=1e18;

ll dp[2][100010];

void dijkstra(int c){
    for(int i=0;i<=N;i++) dist[c][i]=INF;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    if(c==0){
        dist[c][S]=0;
        PQ.push(mkp(0,S));
    }else{
        dist[c][T]=0;
        PQ.push(mkp(0,T));
    }

    while(!PQ.empty()){
        int now;
        ll cost;
        tie(cost,now)=PQ.top();
        PQ.pop();

        if(dist[c][now]<cost) continue;
        for(int i=0;i<g[now].size();i++){
            int nex;
            ll neco;
            tie(nex,neco)=g[now][i];
            if(dist[c][nex]>dist[c][now]+neco){
                dist[c][nex]=dist[c][now]+neco;
                PQ.push(mkp(dist[c][nex],nex));
            }
        }
    }
}

void add(ll &a,ll b){
    a=(a+b)%MOD;
}

void setRoutes(int c){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
    vector<int> used(N+1,0);
    if(c==0){
        dp[c][S]=1;
        PQ.push(mkp(0,S));
        used[S]=1;
    }else{
        dp[c][T]=1;
        PQ.push(mkp(0,T));
        used[T]=1;
    }

    while(!PQ.empty()){
        int now;
        ll cost;
        tie(cost,now)=PQ.top();
        PQ.pop();

        for(int i=0;i<g[now].size();i++){
            int nex;
            ll neco;
            tie(nex,neco)=g[now][i];
            int tar=T;
            if(c==1) tar=S;
            if(dist[c][now]+neco+dist[1-c][nex]==dist[c][tar]){
                add(dp[c][nex],dp[c][now]);
                if(used[nex]==0){
                    used[nex]=1;
                    PQ.push(mkp(dist[c][nex],nex));
                }
            }
        }
    }
}

void mul(ll &a,ll b){
    a=a*b%MOD;
}

int main(){
  cin>>N>>M;
  cin>>S>>T;
  rep(i,M){
      ll a,b,c;
      cin>>a>>b>>c;
      edges.push_back(mkt(a,b,c));
      g[a].push_back(mkp(b,c));
      g[b].push_back(mkp(a,c));
  }

  dijkstra(0);
  dijkstra(1);

  setRoutes(0);
  setRoutes(1);

  ll ans=dp[0][T];
  mul(ans,dp[1][S]);
  for(int i=1;i<=N;i++){
      if(dist[0][i]+dist[1][i]==dist[0][T]&&dist[0][i]==dist[1][i]){
          ll res=dp[0][i];
          mul(res,dp[1][i]);
          mul(res,res);
          add(ans,MOD-res);
      }
  }

  for(int i=0;i<M;i++){
      ll a,b,c;
      a=get<0>(edges[i]);
      b=get<1>(edges[i]);
      c=get<2>(edges[i]);

      if(dist[0][a]>dist[0][b]) swap(a,b);
      if(dist[0][a]+c+dist[1][b]==dist[0][T]){
          if(abs(dist[0][a]-dist[1][b])<c){
              ll res=dp[0][a];
              mul(res,dp[1][b]);
              mul(res,res);
              add(ans,MOD-res);
          }
      }
  }
  
  add(ans,MOD);
 
  cout<<ans<<endl;


  return 0;
}
