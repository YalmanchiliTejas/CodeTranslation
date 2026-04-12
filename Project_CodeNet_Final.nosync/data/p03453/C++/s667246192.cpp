#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int N,M;

int S,T;

struct edge{
  int to;
  i64 cost;
};

vector<vector<edge>> G;


i64 MOD = 1e9 + 7;

vector<i64> dij(int s){
  vector<i64> dist(N,1e17);
  dist[s] = 0;
  using P = pair<i64,i64>;
  priority_queue<P,vector<P>,greater<P>> que;

  que.push({dist[s],s});

  while(!que.empty()){
    int v = que.top().second;
    i64 d = que.top().first;
    que.pop();

    for(auto e : G[v]){
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        que.push({dist[e.to],e.to});
      }
    }
  }

  return dist;

  return dist;
}

int main(){
  cin >> N >> M;
  cin >> S >> T;
  S--;
  T--;

  G.resize(N);

  vector<int> u(M),v(M);
  vector<i64> d(M);

  rep(i,0,M - 1){
    cin >> u[i] >> v[i] >> d[i];
    u[i]--;
    v[i]--;
    G[u[i]].push_back({v[i],d[i]});
    G[v[i]].push_back({u[i],d[i]});
  }
  auto D = dij(S);
  auto rD = dij(T);

  vector<i64> co(N,0),rco(N,0);
  co[S] = 1;
  rco[T] = 1;
  {

    vector<pair<i64,int>> vec;
    rep(i,0,N - 1){
      vec.push_back({D[i],i});
    }
    sort(vec.begin(),vec.end());
    for(auto p : vec){
      int v = p.second;
      for(auto e : G[v]){
        if(D[e.to] == D[v] + e.cost){
          (co[e.to] += co[v]) %= MOD;
        }
      }
    }
    reverse(vec.begin(),vec.end());
    for(auto p : vec){
      int v = p.second;
      for(auto e : G[v]){
        if(D[e.to] == D[v] - e.cost){
          (rco[e.to] += rco[v]) %= MOD;
        }
      }
    }
  }

  i64 sum = co[T] * rco[S] % MOD;

  i64 sub = 0;

  rep(i,0,N - 1){
    if(D[i] * 2 == D[T]){
      (sub += co[i] * rco[i] % MOD * co[i] % MOD * rco[i] % MOD) %= MOD;
    }
  }

  rep(i,0,M - 1){
    if(D[u[i]] > D[v[i]]) swap(u[i],v[i]);
    if(D[u[i]] * 2 < D[T] && D[v[i]] * 2 > D[T] && D[u[i]] + d[i] == D[v[i]]){
      (sub += co[u[i]] * rco[v[i]] % MOD * co[u[i]] % MOD * rco[v[i]] % MOD) %= MOD;
    }
  }

  cout << (sum + MOD - sub) % MOD << endl;
}
