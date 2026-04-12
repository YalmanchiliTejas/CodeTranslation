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

#define MAX 10000
#define INFTY (1<<29)

vector<pair<int,ll>> g[4040];

class DisjointSet{
public:
  vector<int> rank,p;

  DisjointSet() {}
  DisjointSet(int size){
    rank.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) makeSet(i);
  }

  void makeSet(int x){
    p[x]=x;
    rank[x]=0;
  }

  bool same(int x,int y){
    return findSet(x)==findSet(y);
  }

  void unite(int x,int y){
    link(findSet(x),findSet(y));
  }

  void link(int x,int y){
    if(rank[x]<rank[y]){
      p[y]=x;
    }else{
      p[x]=y;
      if(rank[x]==rank[y]){
        rank[y]++;
      }
    }
  }

  int findSet(int x){
    if(x!=p[x]){
      p[x]=findSet(p[x]);
    }
    return p[x];
  }
};

class Edge{
public:
  ll source,target,cost;
  Edge(int source=0,int target=0,ll cost=0):
  source(source),target(target),cost(cost){}
  bool operator < (const Edge &e) const{
    return cost < e.cost;
  }
};

ll kruskal(int N,vector<Edge> edges){//long long?
  ll totalCost=0;
  sort(edges.begin(),edges.end());
  DisjointSet dset=DisjointSet(N+1);

  for(int i=0;i<N;i++) dset.makeSet(i);

  int source,target;
  for(int i=0;i<edges.size();i++){
    Edge e=edges[i];
    if(!dset.same(e.source,e.target)){
      // MST.push_back(e);
      g[e.source].push_back(make_pair(e.target,e.cost));
      g[e.target].push_back(make_pair(e.source,e.cost));
      totalCost+=e.cost;
      dset.unite(e.source,e.target);
    }
  }
  return totalCost;
}

int N,M;
int Q;

bool used[4040];
int ma[4040][4040];

vector<int> dfs(int now){
    used[now]=true;
    vector<int> v[g[now].size()];
    vector<int> res;
    for(int i=0;i<g[now].size();i++){
        int next=g[now][i].first;
        if(used[next]) continue;
        vector<int> child=dfs(next);
        for(int j=0;j<child.size();j++){
            v[i].push_back(child[j]);
            res.push_back(child[j]);
        }
    }

    for(int i=0;i<g[now].size();i++){
        if(v[i].size()==0) continue;
        int next=g[now][i].first;
        int cost=g[now][i].second;
        for(int j=0;j<v[i].size();j++){
            int target=v[i][j];
            ma[now][target]=max(cost,ma[next][target]);
            ma[target][now]=max(cost,ma[next][target]);
        }
    }
    
    for(int i=0;i<g[now].size();i++){
        if(v[i].size()==0) continue;
        for(int j=i+1;j<g[now].size();j++){
            if(v[j].size()==0) continue;
            for(int k=0;k<v[i].size();k++){
                for(int l=0;l<v[j].size();l++){
                    ma[v[i][k]][v[j][l]]=max(ma[v[i][k]][now],ma[v[j][l]][now]);
                    ma[v[j][l]][v[i][k]]=max(ma[v[i][k]][now],ma[v[j][l]][now]);
                }
            }
        }
    }
    res.push_back(now);
    return res;
}

int main(){
  cin>>N>>M;
  vector<Edge> edges;
  for(int i=0;i<M;i++){
      int a,b,c;
      cin>>a>>b>>c;
      a--;
      b--;
      edges.push_back(Edge(a,b,c));
  }

  ll ans=kruskal(N,edges);
  vector<int> x=dfs(0);

  cin>>Q;
  for(int i=0;i<Q;i++){
      int s,t;
      cin>>s>>t;
      s--;
      t--;
      cout<<ans-ma[s][t]<<endl;
  }

  return 0;
}
