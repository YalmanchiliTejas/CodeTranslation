// abco54c: One-stroke Path
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define rep(i,n) for(int i=0;i<(n);i++)
#define in(x) cin>>(x)
#define oute(x) cout<<(x)<<endl

struct vertex{vi v; bool visit;};
using graph = vector<vertex>;

void dfs(graph &g, int p, int distance, int &count){
  if(distance==g.size()-1){ count++; return; }
  g[p].visit = true;
  for(int c:g[p].v)
    if(!g[c].visit) dfs(g,c,distance+1,count);
  g[p].visit = false;
}

int main(){
  int n,m; in(n);in(m);
  graph g(n);
  rep(i,m){
    int a,b; in(a);in(b);
    g[--a].v.push_back(--b);
    g[b].v.push_back(a);
  }
  int count = 0;
  dfs(g,0,0,count);
  oute(count);
}