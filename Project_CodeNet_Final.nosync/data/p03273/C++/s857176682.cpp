#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> str(N, vector<char>(M));
  vector<int> x(N), y(M);
  for (int i = 0; i < N; i++){
    for (int j =0; j < M; j++){
      cin >> str.at(i).at(j);
      if (str.at(i).at(j) == '#'){
        x.at(i) = 1;
        y.at(j) = 1;
      }
    }
  }
  for (int i = 0; i < N; i++){
    if(x.at(i) == 0) continue;
    for (int j =0; j < M; j++){
      if (y.at(j) == 0) continue;
      cout << str.at(i).at(j);
    }
    cout << endl;
  }
}