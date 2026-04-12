#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G(8);
int cntPath = 0;
int N, M;

void bfs(int cnt, int pos, vector<int> checked){
  
  if(cnt == N - 1){
    for(int j = 0; j < N; j++){
      if(checked.at(j) == 0) return;
    }
    cntPath++;
    return;
  }
  cnt++;
  for(int i = 0; i < G.at(pos).size(); i++){
    vector<int> ch = checked;
    ch.at(G.at(pos).at(i)) = 1;
    bfs(cnt, G.at(pos).at(i), ch);
  }
  return;
}


int main(){
  
  cin >> N >> M;
  int i;
  
  for(i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    G.at(a - 1).push_back(b - 1);
    G.at(b - 1).push_back(a - 1);
  }
  
  vector<int> ZeroVec(N, 0);
  ZeroVec.at(0) = 1;
  bfs(0, 0, ZeroVec);
  cout << cntPath << endl;
  return 0;
}