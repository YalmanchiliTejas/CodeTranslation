#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N,M;
int S,T;
vector<pair<int,ll>> g[100010];
ll dist[100010];
#define INF 1e16

void dijkstra(){
    priority_queue<pair<ll,int>> PQ;
    for(int i=0;i<N;i++) dist[i]=INF;
    dist[S]=0;
    PQ.push(make_pair(0,S));
    
    while(PQ.size()){
        pair<ll,int> tp=PQ.top();
        PQ.pop();
        int now=tp.second;
        if(dist[now]<tp.first*(-1)) continue;

        for(int i=0;i<g[now].size();i++){
            int next=g[now][i].first;

            if(dist[now]+g[now][i].second<dist[next]){
                dist[next]=dist[now]+g[now][i].second;
                PQ.push(make_pair(dist[next]*(-1),next));
            }
        }
    }
    return;
}

int main(){
  cin>>N>>M;
  cin>>S>>T;
  S--;
  T--;
  for(int i=0;i<M;i++){
      int u,v,d;
      cin>>u>>v>>d;
      u--;
      v--;
      g[u].push_back(make_pair(v,d));
      g[v].push_back(make_pair(u,d)); 
  }

  dijkstra();
  vector<pair<ll,int>> d;
  for(int i=0;i<N;i++){
      if(dist[i]>dist[T]) continue;
      d.push_back(make_pair(dist[i],i));
  }
  sort(d.begin(),d.end());

  ll dp1[N+1]={},dp2[N+1]={};
  dp1[S]=1;
  dp2[T]=1;
  for(int i=0;i<d.size();i++){
      int now=d[i].second;
      for(int j=0;j<g[now].size();j++){
          int next=g[now][j].first;
          if(dist[now]+g[now][j].second==dist[next]){
              dp1[next]=(dp1[next]+dp1[now])%MOD;
          }
      }
  }

  reverse(d.begin(),d.end());
  for(int i=0;i<d.size();i++){
      int now=d[i].second;
      for(int j=0;j<g[now].size();j++){
          int back=g[now][j].first;
          if(dist[now]==g[now][j].second+dist[back]){
              dp2[back]=(dp2[back]+dp2[now])%MOD;
          }
      }
  }

  ll ans=(dp1[T]*dp1[T])%MOD;
  for(int i=0;i<N;i++){
      if(dist[i]*2==dist[T]){
          ll dec=dp1[i]*dp1[i]%MOD*dp2[i]%MOD*dp2[i]%MOD;
          ans=ans-dec;
          ans=(ans+MOD)%MOD;
      }
  }

  for(int i=0;i<N;i++){
      for(int j=0;j<g[i].size();j++){
          int next=g[i][j].first;
          if(dist[i]*2<dist[T]&&dist[next]*2>dist[T]){
              if(dist[i]+g[i][j].second!=dist[next]) continue;
              ll dec=dp1[i]*dp1[i]%MOD*dp2[next]%MOD*dp2[next]%MOD;
              ans=ans-dec;
              ans=(ans+MOD)%MOD;
          }
      }
  }
  cout<<(ans+MOD)%MOD<<endl;


  return 0;
}
