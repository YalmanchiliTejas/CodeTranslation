#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
typedef long long ll;
const ll INF = (1LL<<60);
ll mod = 1e9+7;
struct edge{ ll to,cost; };

int N,M;
int S,T;
vector<edge> G[MAX];

ll sd[MAX];
ll td[MAX];
ll sp[MAX];
ll tp[MAX];

void dijkstra(int S,ll sd[MAX],ll sp[MAX]){
  for(int i=0;i<MAX;i++){
    sd[i]=INF;
    sp[i]=0;
  }
  sd[S]=0;
  sp[S]=1;
  typedef pair<ll,ll> P;
  priority_queue< P , vector<P> , greater<P> > Q;
  Q.push( P(0,S) );
  while(!Q.empty()){
    P p=Q.top();
    Q.pop();
    ll pos=p.second;
    ll cost=p.first;
    if( cost > sd[pos])continue;
    
    for(int i=0;i<(int)G[pos].size();i++){
      edge e=G[pos][i];
      if( sd[e.to] > cost+e.cost ){
        sd[e.to]=cost+e.cost;
        sp[e.to]=sp[pos];
        Q.push( P(sd[e.to], e.to) );
      }else if(sd[e.to]==cost+e.cost){
        sp[e.to]+=sp[pos];
        sp[e.to]%=mod;
      }
    }
  }
}

int main(){
  cin>>N>>M;
  cin>>S>>T;
  S--;
  T--;
  
  for(int i=0;i<M;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    G[a].push_back( (edge){b,c} );
    G[b].push_back( (edge){a,c} );
  }
  
  dijkstra(S,sd,sp);
  dijkstra(T,td,tp);

  ll dist = sd[T];
  ll total = (sp[T]*tp[S])%mod;
  //  cout<<dist<<' '<<total<<endl;
  
  //  cout<<total<<endl;
  
  for(int from=0;from<N;from++){
    for(int j=0;j<(int)G[from].size();j++){
      ll to=G[from][j].to;
      ll cost=G[from][j].cost;
      if( sd[from] + td[to] + cost != dist )continue;
      if( sd[from]*2 >= dist || td[to]*2 >= dist)continue;
      ll tmp = (sp[from]*tp[to])%mod;
      tmp = (tmp*sp[from])%mod;
      tmp = (tmp*tp[to])%mod;
      
      total += (mod-tmp);
      total %= mod;      
    }
  }
  
  for(int v=0;v<N;v++){
    if(sd[v]!=td[v])continue;
    if(sd[v]+td[v]!=dist)continue;
    
    ll tmp = (sp[v]*tp[v])%mod;
    tmp = (tmp*tp[v])%mod;
    tmp = (tmp*sp[v])%mod;
    
    total += (mod-tmp);
    total %= mod;
  }

  cout<<total<<endl;
  return 0;
}
