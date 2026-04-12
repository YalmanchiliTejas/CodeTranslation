#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

//#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;
struct HopcroftKarp {
  vector< vector< int > > graph;
  vector< int > dist, match;
  vector< bool > used, vv;

  HopcroftKarp(int n, int m) : graph(n), match(m, -1), used(n) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
  }

  void bfs() {
    dist.assign(graph.size(), -1);
    queue< int > que;
    for(int i = 0; i < graph.size(); i++) {
      if(!used[i]) {
        que.emplace(i);
        dist[i] = 0;
      }
    }

    while(!que.empty()) {
      int a = que.front();
      que.pop();
      for(auto &b : graph[a]) {
        int c = match[b];
        if(c >= 0 && dist[c] == -1) {
          dist[c] = dist[a] + 1;
          que.emplace(c);
        }
      }
    }
  }

  bool dfs(int a) {
    vv[a] = true;
    for(auto &b : graph[a]) {
      int c = match[b];
      if(c < 0 || (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {
        match[b] = a;
        used[a] = true;
        return (true);
      }
    }
    return (false);
  }

  int bipartite_matching() {
    int ret = 0;
    while(true) {
      bfs();
      vv.assign(graph.size(), false);
      int flow = 0;
      for(int i = 0; i < graph.size(); i++) {
        if(!used[i] && dfs(i)) ++flow;
      }
      if(flow == 0) return (ret);
      ret += flow;
    }
  }

  void output() {
    for(int i = 0; i < match.size(); i++) {
      if(~match[i]) {
        cout << match[i] << "-" << i << endl;
      }
    }
  }
};
template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

WeightedGraph<ll> G;
ll d;
vector<ll> Dist1,Dist2;
vector<ll> cnt1,cnt2;
template< typename T >
pair<vector< T >,vector<T>> dijkstra(int s) {
    WeightedGraph<ll> g=G;
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);
  vector<T> cnt(g.size());
  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  cnt[s]=1;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] < next_cost) continue;
      bool flag=true;
      if(dist[e.to]==next_cost)flag=false;
      if(flag)cnt[e.to]=0;
      dist[e.to] = next_cost;
      cnt[e.to]=(cnt[e.to]+cnt[idx])%MOD;
      if(flag)
      que.emplace(dist[e.to], e.to);
    }
  }
  return pair<vector<T>,vector<T>>(dist,cnt);
}

ll dijkstra2(int s){
    const auto INF=numeric_limits<ll>::max();
    vector<ll> dist(G.size(),INF);
    vector<ll> cnt1(G.size(),0);
    cnt1[s]=1;
    ll ans=0;
    using p=pair<ll,int>;
    priority_queue<p,vector<p>,greater<p>> que;
    dist[s]=0;
    que.emplace(0,s);
    while(!que.empty()){
        ll cost;int idx;
        tie(cost,idx)=que.top();que.pop();
        if(dist[idx]<cost)continue;
        for(auto &e:G[idx]){
            ll next=cost+e.cost;
            //cout<<idx<<" "<<e.to<<" "<<next<<endl;
            if(dist[e.to]<next)continue;
            bool flag=true;
            if(dist[e.to]==next)flag=false;
            if(next+Dist2[e.to]!=d)continue;
            if(flag)cnt1[e.to]=0;
            dist[e.to]=next;
            cnt1[e.to]=(cnt1[e.to]+cnt1[idx])%MOD;
            if(cost*2<d&&d<next*2){
                //cout<<idx<<" "<<e.to<<" "<<endl;
                ans=(ans+cnt1[idx]*cnt1[idx]%MOD*cnt2[e.to]%MOD*cnt2[e.to]%MOD)%MOD;
                continue;
            }
            if(cost*2==d){
                ans=(ans+cnt1[idx]*cnt1[idx]%MOD*cnt2[idx]%MOD*cnt2[idx]%MOD)%MOD;
                break;
            }
            if(flag)
            que.emplace(d-Dist2[e.to],e.to);
        }
    }
    return ans;
}

main(){
    int n=in(),m=in();
    int s=in(),t=in();
    G.resize(n+1);
    rep(i,m){
        int a=in(),b=in();ll c=in();
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    //auto temp=dijkstra<ll>(s);
    //Dist1=temp.first,cnt1=temp.second;
    auto temp=dijkstra<ll>(t);
    Dist2=temp.first,cnt2=temp.second;
    d=Dist2[s];
    //cout<<d<<endl;
    ll ans=dijkstra2(s);
    //cout<<cnt1[t]*cnt1[t]<<endl;
    cout<<(cnt2[s]*cnt2[s]%MOD+MOD-ans)%MOD<<endl;
}
