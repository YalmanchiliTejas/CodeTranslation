#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vec(vector<vector<int> > g,int N){
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << g.at(i).at(j);
    }
  cout << endl;
  }
}
int N,M;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int ans= 0;
vector<vector<int> > G(N+1, vector<int>(N+1));

void dfs1(int i,vector<int> visited){
  bool all_visited = true;
  //cout << "visited: " << i << endl;
  for(int s = 0; s < N;s++){
    //cout << visited.at(s) << " ";
    if(visited.at(s) == 0)
      all_visited = false;
  }
  //cout << endl;
  if(all_visited){
    //cout << "ans++"<<endl;
    ans+=1;
    return;
  }
  for(int n = 0; n < N; n++){
    if(G.at(i).at(n) == 0)continue;
    if(visited.at(n) == 1)continue;
    visited.at(n) = 1;
    dfs1(n,visited);
    visited.at(n) = 0;
  }
  return ;
}
int dfs(int v, int N,vector<int> visited){
  bool all_visited = true;
  for(int i = 0; i < N; i++){
    if(visited.at(i) == 0){
      all_visited = false;
    }
  }
  if(all_visited){
    return 1;
  }
  int ret = 0;
  for(int i= 0;i < N; ++i){
    if(G[v][i] == 0)continue;
    if(visited[i])continue;

    visited.at(i) = 1;
    ret += dfs(i,N,visited);
    visited.at(i) = 0;
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int  a, b,res;
  vector<int > visited(N);
  cin >> N >> M;
  G.assign(N, vector<int>(N,0));
  visited.assign(N,0);
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    a--;b--;
    G.at(a).at(b) = 1;
    G.at(b).at(a) = 1;
  }
  //print_vec(G,N);
  visited.at(0) = 1;
  //res = dfs(0,N,visited);
  dfs1(0,visited);
  cout << ans << endl;
  //cout << res << endl;
  return 0;
}
