#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <map>
#include <list>
using namespace std;
int N,M;
int ans = 0 , cnt = 0;
vector<vector<int>> G;
vector<bool> visited;

void dfs(int v){
  visited.at(v) = true;
  cnt++;
  if(cnt == N){
    ans++;
    return;
  }
  for(int i = 0; i < N; i++){
    if(G.at(v).at(i) == 1 && visited.at(i) == false){
      int temp_cnt = cnt;
      vector<bool> temp_visited(visited);
      dfs(i);
      cnt = temp_cnt;
      visited = temp_visited;
    }
  }
}

int main(){
  cin >> N >> M;
  G = vector<vector<int>>(N,vector<int>(N,0));
  visited = vector<bool>(N,false);
  
  for(int i = 0; i < M; i++){
    int a,b; cin >> a >> b;
    a--;
    b--;
    G.at(a).at(b) = 1;
    G.at(b).at(a) = 1;
  }
  dfs(0);
  cout << ans << endl;
}