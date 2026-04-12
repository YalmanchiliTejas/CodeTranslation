
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int n, m;
bool graph[10][10], visited[10];

int dfs(int i){
  int sum = 0;
  bool flag = true;
  rep(j, n){
    if(!visited[j]){
      flag = false;
    }
  }
  if(flag){
    //cerr <<" path"<< endl;
    return 1;
  }
  rep(j, n){
    if(graph[i][j] && !visited[j]){
      //cerr << j << " ";
      visited[j] = true;
      sum += dfs(j);
      visited[j] = false;
    }
  }
  //cerr << endl;
  return sum;
}

int main(){
  cin >> n >> m;
  rep(i, n)rep(j, n) graph[i][j] = false;
  rep(i, n) visited[i] = false;
  visited[0] = true;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a][b] = graph[b][a] = true;
  }
  //rep(i, n){rep(j, n) cerr << graph[i][j]; cerr << endl;} 
  cout << dfs(0) << endl;
  return 0;
}
