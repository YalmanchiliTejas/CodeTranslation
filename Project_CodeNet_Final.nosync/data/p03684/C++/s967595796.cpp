#include<bits/stdc++.h>
using namespace std;
#define int long long

struct edge{ int to,cost; };
const int N = 2e5+10;
vector< edge > G[N];

int prim(){
  typedef pair<int, int> P;
  const int INF = 1 << 30;

  priority_queue<P,vector<P>,greater<P>> que;
  vector<bool> visited(N,false);

  que.push({0,0}); //{距離,頂点}
  int total = 0;

  while( !que.empty() ){
    P p = que.top(); que.pop();
    int v = p.second;
    if(visited[v]) continue;
    visited[v] = true;
    total += p.first;
    for(auto e : G[v]){
      if(!visited[e.to]){
        que.push({e.cost,e.to});
      }
    }
  }
  return total;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector< pair<pair<int,int>,int> > X,Y;
  for(int i = 0; i < n; i++){
    int x,y; cin >> x >> y;
    X.push_back({{x,y},i});
    Y.push_back({{y,x},i});
  }
  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());

  for(int i = 0; i < n-1; i++){
    int from = X[i].second;
    int a = X[i].first.first;
    int to = X[i+1].second;
    int c = X[i+1].first.first;
    G[from].push_back({to,abs(a-c)});
    G[to].push_back({from,abs(a-c)});
  }

  for(int i = 0; i < n-1; i++){
    int from = Y[i].second;
    int b = Y[i].first.first;
    int to = Y[i+1].second;
    int d = Y[i+1].first.first;
    G[from].push_back({to,abs(b-d)});
    G[to].push_back({from,abs(b-d)});
  }

  cout << prim() << endl;

  return 0;
}
