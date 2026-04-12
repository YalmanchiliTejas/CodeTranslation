// abco54c: One-stroke Path
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define rep(i,n) for(int i=0;i<(n);i++)
#define oute(x) cout<<(x)<<endl

struct vertex{vi v; bool visit;};
using graph = vector<vertex>;

int dfs(graph &g, int p, int distance, int count){
  if(distance==g.size()-1) return count+1;
  g[p].visit = true;
  for(int c:g[p].v)
    if(!g[c].visit) count = dfs(g,c,distance+1,count);
  g[p].visit = false;
  return count;
}

int main(){
  int n,m; cin>>n>>m;
  graph g(n);
  rep(i,m){
    int a,b; cin>>a>>b;
    g[--a].v.push_back(--b);
    g[b].v.push_back(a);
  }
  oute(dfs(g,0,0,0));
}