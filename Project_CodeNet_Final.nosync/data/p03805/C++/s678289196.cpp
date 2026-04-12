#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

bool graph[8][8];
bool visited[8];

int dfs(int a, int n){
  bool all_visited = true;
  fr(i,n) if(visited[i] == false) all_visited = false;
  if(all_visited) return 1;
  int ret = 0;
  fr(i, n) {
    if(visited[i]) continue;
    if(graph[a][i] == true){
      visited[i] = true;
      ret += dfs(i, n);
      visited[i] = false;
    }
  }  
  return ret;
}

int main(void) {
  int n,m;cin>>n>>m;
  fr(i, m) {
    int a,b;cin>>a>>b;
    a--;b--;
    graph[a][b] = graph[b][a] = true;
  }
 // bool visited[8];
  fr(i, n) visited[i] = false;
  visited[0] = true;
  cout << dfs(0, n) << endl;
  return 0;
}