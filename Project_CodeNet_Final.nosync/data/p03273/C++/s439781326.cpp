#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  bool B=0;
  cin >> N >> M;
  vector<vector<char>> str(N, vector<char>(M));
  vector<int> x(N), y(M);
  for (int i = 0; i < N; i++){
    B = 0;
    for (int j =0; j < M; j++){
      cin >> str.at(i).at(j);
      if (str.at(i).at(j) != '.'){
        B = 1;
      }
    }
    if(B == 0){
      x.at(i) = 1;
    }
  }
  for (int i = 0; i < M; i++){
    B = 0;
    for (int j = 0; j < N; j++){
      if(str.at(j).at(i) != '.'){
        B = 1;
        break;
      }
    }
    if(B == 0){
      y.at(i) = 1;
    }
  }
  for (int i = 0; i < N; i++){
    if(x.at(i) == 1) continue;
    for (int j =0; j < M; j++){
      if (y.at(j) == 1) continue;
      cout << str.at(i).at(j);
    }
    cout << endl;
  }
}