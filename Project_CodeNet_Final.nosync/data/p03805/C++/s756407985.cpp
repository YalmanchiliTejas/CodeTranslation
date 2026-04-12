#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;  
  //　グラフを隣接行列で管理
  vector<vector<int>> graph(N, vector<int>(N));
  for(int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    graph.at(x).at(y) = graph.at(y).at(x) = 1;
  }

  // 順列(0, 1, 2, ……)
  vector<int> ord(N);
  for(int i = 0; i < N; i++){
    ord.at(i) = i;
  }

  // 順列を全部試す
  int ans = 0;
  do{
    if(ord.at(0) != 0) break; // 1から始まっていない順列は調べない

    bool ok = true;
    for(int i = 0; i + 1 < N; i++){
      int from = ord.at(i);
      int to = ord.at(i + 1);
      if(!graph.at(from).at(to)){
        ok = false;
      }
    }
    if(ok){
      ans++;
    }
  }while(next_permutation(ord.begin(), ord.end()));

  cout << ans << endl;
}