#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<int>> G(8);
int seen[8];
int counter = 0;
int sum = 0;

void func(int i){

  // seen[i] = 1;
  //全てが探索済みならカウントを＋＋

  sum = 0;

  for(int i = 0; i < n; i++){
    sum += seen[i];
  }
  if(sum == n) counter ++;

  // printf("now = %d\r\n",i);
  

  for(auto&& next : G[i]){
  // for (int next = 0; next < n; next++){
    // printf("next = %d\r\n",next);
    // printf("seen next = %d\r\n",seen[next]);
    if(seen[next] == 0) {
      // printf("now = %d\r\n",i);
      // printf("next = %d\r\n",next);
      seen[next] = 1;
      func(next);
      seen[next] = 0;
    }
    //else {
      // //全てが探索済みならカウントを＋＋
      // for(int i = 0; i < n; i++){
      //   sum += seen[i];
      // }
      // if(sum == n) counter ++;
    // }
  }

  return;
}

int main(){
  
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    G.at(a-1).push_back(b-1);
    G.at(b-1).push_back(a-1);
    // printf("G[a] = %d\r\n",G[a][i]);
    // printf("G[b] = %d\r\n",G[b][i]);
  }
  // printf("G[0]size = %d\r\n",G.at(1).size());
  // for(int j = 0; j < G.at(0).size(); j++){
  //   printf("G[0] = %d\r\n",G[0][j]);
  // }

  for (int i = 0; i < n; i++) seen[i] = 0;

  seen[0] = 1;
  func(0);
  cout << counter << endl;

  
  return 0;
}