#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力
  int N, M;
  cin >> N >> M;
  
  vector<pair<int,int>> p(M);
  for (int i = 0; i < M; i++) {
    cin >> p.at(i).first >> p.at(i).second;
  }
  
  // 頂点
  vector<int> edge(N);
  for (int i = 0; i < N; i++) {
    edge.at(i) = (i + 1);
  }  
  
  int count = 0;
  do {
    bool o = true;
    for (int i = 0; i < (N - 1); i++) {
      int pos1 = edge.at(i);
      int pos2 = edge.at(i + 1);
      
      bool ok = false;
      for (int j = 0; j < M; j++) {
        if ((p.at(j).first == pos1 && p.at(j).second == pos2) ||
            (p.at(j).first == pos2 && p.at(j).second == pos1)
           ) {
          ok = true;
          break;
        }
      }
      if (!ok) { // 対応する辺が見つからなかった
        o = false;
        break;
      }
    } 
    if (o) {
      count++;
    }
  } while (next_permutation(edge.begin() + 1, edge.end()));
  
  cout << count << endl;
}
