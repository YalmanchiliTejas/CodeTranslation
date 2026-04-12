#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 200

typedef long long ll;

class Edge{
public:
  int from,to;
  ll cost;
  Edge(){}
  Edge(int _from,int _to,ll _cost){
    from = _from;
    to = _to;
    cost = _cost;
  }
  bool operator<(const Edge &e)const{
    return cost > e.cost;
  }
};

int n,m;
ll ans;
vector<Edge> t[102];
vector<Edge> es;

/*
int par[MAX_N];
int rank[MAX_N];

void init(void){
  rep(i,MAX_N){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  } else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return;

  if(rank[x] < rank[y]){
    par[x] = y;
  } else{
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}

bool same(int x,int y){
  return find(x) == find(y);
}
*/

int dfs(int idx,bool *used){
  int res = 1;
  used[idx] = true;
  for(int i=0;i<t[idx].size();i++){
    Edge e = t[idx][i];
    if(!used[e.to]){
      res += dfs(e.to,used);
    }
  }
  return res;
}

void solve(){
  sort(es.begin(),es.end());

  int group[2] = {-1,-1};
  int size = 0;

  for(int i=0;i<es.size();i++){
    Edge e = es[i];

    t[e.from].push_back(e);
    t[e.to].push_back(Edge(e.to,e.from,e.cost));

    bool used[102];
    memset(used,0,sizeof(used));
    int tmp = dfs(e.from,used);

    if(tmp == n){
      t[e.from].erase(t[e.from].end() - 1);
      t[e.to].erase(t[e.to].end() - 1);
      ans += e.cost;
    }
  }

  cout<<ans<<endl;
}

int main(){
  while(cin>>n>>m,n||m){
    ans = 0;
    es.clear();
    for(int i=0;i<n;i++) t[i].clear();

    for(int i=0;i<m;i++){
      Edge e;
      cin>>e.from>>e.to>>e.cost;
      if(e.cost <= 0){
        ans += e.cost;
      }
      else{
        es.push_back(e);
      }
    }

    solve();
  }
}