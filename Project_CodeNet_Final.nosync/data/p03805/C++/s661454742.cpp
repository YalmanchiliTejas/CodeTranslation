#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE 8

int dfs(bool graph[MAX_NODE][MAX_NODE], int curr, int n, bool hist[])
{
  int i=0;
  for(i=0; i<n; i++){
    if(!hist[i])
      break;
  }
  if(i==n){
    //printf("all\n");
    return 1;
  }
  int ret=0;
  for(i=0; i<n; i++){
    if(graph[curr][i] && !hist[i]){
      //printf("next %d\n", i+1);
      hist[i] = true;
      ret += dfs(graph, i, n, hist);
      //printf("--\n");
      hist[i] = false;
    }
  }
  return ret;
}

int main()
{
  int n, m;
  cin >> n >> m;
  
  bool graph[MAX_NODE][MAX_NODE];
  bool hist[MAX_NODE];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
		graph[i][j] = 0;
    }
    hist[i] = 0;
  }
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = 1;
  }
  
  hist[0] = true;
  int ret = dfs(graph, 0, n, hist);
  
  cout << ret << endl;
  
  return 0;
}
