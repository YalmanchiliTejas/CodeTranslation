// abco54c: One-stroke Path
#include <bits/stdc++.h>
using namespace std;

struct vertex{vector<int> v; bool visit;};
using graph = vector<vertex>;

int dfs(graph &g, int p, int v_count){
  if(v_count==g.size()) return 1;
  int count = 0;
  g[p].visit = true;
  for(int c:g[p].v) if(!g[c].visit) count += dfs(g,c,v_count+1);
  g[p].visit = false;
  return count;
}

int main(){
  int n,m; cin>>n>>m;
  graph g(n);
  for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    g[--a].v.push_back(--b);
    g[b].v.push_back(a);
  }
  cout<<dfs(g,0,1)<<endl;
}