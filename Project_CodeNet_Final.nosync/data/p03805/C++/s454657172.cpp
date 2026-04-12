#include <bits/stdc++.h>
using namespace std;

bool visit[8][8];

int ans(int v, int N, bool *visited){

  int ret=0;
  bool all_visited;

  all_visited = true;
  for(int i=0; i<N; i++){
    if(!visited[i]) all_visited=false;
  }
  if(all_visited) return 1;

  for(int i=0; i<N; i++){
    if(visit[v][i] && !visited[i]){
      visited[i]=true;
      ret += ans(i,N,visited);
      visited[i]=false;
    }
  }

  return ret;
}

int main(){

  bool visited[8];
  for(int i=0; i<8; i++) visited[i]=false;
  visited[0]=true;

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      visit[i][j] = false;
    }
  }

  int N,M;
  cin >> N >> M;
  int a[M],b[M];
  for(int i=0; i<M; i++){
    cin >> a[i] >> b[i];
    visit[a[i]-1][b[i]-1]=true;
    visit[b[i]-1][a[i]-1]=true;
  }

  cout << ans(0, N, visited) << endl;

  return 0;
}
