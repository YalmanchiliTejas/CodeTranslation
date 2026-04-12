#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e18;

typedef pair<int,int> P;

int n, m, s, t, d[2][100005], cnt[2][100005];
vector<P> G[100005];

void dijkstra(int S, int idx){
  
  for(int i=0;i<n;i++) d[idx][i] = INF;
    
  priority_queue<P,vector<P>,greater<P> > q;
  
  d[idx][S] = 0;
  cnt[idx][S] = 1;
  
  q.push(P( 0, S ));
  
  while( !q.empty() ){
    
    P tmp = q.top(); q.pop();
    
    int node = tmp.second;
    int cost = tmp.first;
    
    if( d[idx][node] < cost ) continue;
    
    for(P p : G[node] ){
      
      int nnode = p.first;
      int ncost = cost + p.second;
      
      if( d[idx][nnode] > ncost ){
	
	d[idx][nnode] = ncost;
	
	cnt[idx][nnode] = cnt[idx][node];
	cnt[idx][nnode] %= mod;
	
	q.push(P( ncost, nnode ));
	
      }
      else if( d[idx][nnode] == ncost ){
	
	cnt[idx][nnode] += cnt[idx][node];
	cnt[idx][nnode] %= mod;
	
      }
      
    }    
    
  }
    
}

int used[100005];

set<P> usede;
set<int> usedn;

void dfs(int x){
  
  if( used[x] ) return;
  used[x] = 1;
  
  usedn.insert( x );
  
  for(P p : G[x] ){
    
    int nx = p.first;
    int cost = p.second;
    
    if( d[0][x] - cost == d[0][nx] ){
      
      usede.insert(P( nx, x ));
      
      dfs( nx );
      
    }
    
  }
  
}

void solve(){
  
  dfs(t);
  
  int ans = 0, all = cnt[0][t] * cnt[0][t], mincost = d[0][t];

  assert( cnt[0][t] == cnt[1][s] );
  
  ans = all % mod;

  for(int i=0;i<n;i++){
    
    if( !usedn.count(i) ) continue;
    
    if( mincost % 2 == 0 && mincost / 2 == d[0][i] ){
      
      int x = cnt[0][i] * cnt[1][i] % mod;
      
      ans = ( ans - x * x % mod + mod );
      
      ans %= mod;
      
    }
    
  }
  
  for(int i=0;i<n;i++){
    
    double mid = mincost / 2.0;
    
    for(P p : G[i] ){
      
      int ni = p.first;
      
      if( !usede.count( P( i, ni ) ) ) continue;
      
      if( d[0][i] < mid && mid < d[0][ni] ){
	
	int x = cnt[0][i] * cnt[1][ni] % mod;
	
	ans = ( ans - x * x % mod + mod );
	
	ans %= mod;

      }
      
    }
    
  }
  
  cout<<ans<<endl;
  
}

signed main(){
  
  cin>>n>>m;

  cin>>s>>t;
  
  s--, t--;
  
  for(int i=0;i<m;i++){
    int u, v, c;
    cin>>u>>v>>c;
    G[u-1].push_back(P(v-1, c));
    G[v-1].push_back(P(u-1, c));
  }
  
  dijkstra( s, 0 );
  
  dijkstra( t, 1 );
  
  solve();
  
  return 0;
}
