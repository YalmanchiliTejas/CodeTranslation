#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> data(N, vector<char>(M));
  vector<int> n(N), m(M);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> data.at(i).at(j);
    }
  }
  for (int i = 0; i < N; i++){
    for (int j =0; j < M; j++){
      if (data.at(i).at(j) == '#'){
        n.at(i) = 1;
        break;
      }
    }
  }
  for (int i = 0; i < M; i++){
    for (int j =0; j < N; j++){
      if (data.at(j).at(i) == '#'){
        m.at(i) = 1;
        break;
      }
    }
  }
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (n.at(i) == 1 && m.at(j) == 1){
        if (j == M-1){
          cout << data.at(i).at(j) << endl;
        }
        else {
          cout << data.at(i).at(j);
        }
      }
      else {
        if (n.at(i) == 1 && j == M-1){
          cout << "" << endl;
        }
      }
    }
  }
}
