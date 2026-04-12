#include<iostream>
using namespace std;

int dfs(bool** graph, int v, bool *visited, int N) {
  
  bool visit_a_vertex = false;
  bool all_visited = true;
  int ret = 0;
  
  for(int i = 0; i < N ; i++) {
    if(!visited[i]){
       all_visited = false; 
    }
  }
  if( all_visited){
     return 1;
  }
  for(int i = 0; i < N; i++) {
    
    
    if(graph[v][i] && !visited[i]) {
       visited[i] = true; 
       ret += dfs(graph,i,visited,N);
       visited[i] = false;
    }

  }

  return ret;
}

int main() {
  
  int N,M;
  cin >> N >> M;
  bool **graph = new bool*[N];
  bool *visited = new bool[N];
  
  for(int i = 0; i < N; i++) {
    graph[i] = new bool[N];
  	visited[i] = false;
  }
    
  for(int i = 0 ; i < M  ;i++) {
    unsigned s,t;
    cin >> s >> t;
    graph[s-1][t-1] = true; 
    graph[t-1][s-1] = true;
  }
  
  visited[0] = true;
  cout << dfs(graph,0,visited,N) << endl;
  
  
  return 0; 
}