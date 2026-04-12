#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
// #include<bits/stdc++.h>
using namespace std;
#define ll long long

int N,M;
vector<vector<bool>> G(10, vector<bool>(10,false));
vector<bool> visited(10, false);

int dfs(int v, int N, vector<bool> visited){
  bool all_visited = true;
  for(int i=0; i<N; i++){
    if(!visited[i]){
      all_visited = false;
    }
  }
  if(all_visited){
    return 1;
  }
  int ret=0;
  for(int i=0; i<N; i++){
    if(!G[v][i]) continue;
    if(visited[i]) continue;

    visited[i] = true;
    ret += dfs(i, N, visited);
    visited[i] = false;
  }
  return ret;
}


int main(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a,b;
    cin >> a >> b;
    G[a-1][b-1] = true;
    G[b-1][a-1] = true;
  }
  visited[0] = true;
  cout << dfs(0,N,visited) << endl;
  return 0;
}
