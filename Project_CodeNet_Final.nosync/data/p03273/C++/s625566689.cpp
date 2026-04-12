#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> masu(N, vector<char>(M)) ;
  for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++){
      cin >> masu.at(i).at(j);
    }
  }
  
  vector<bool> goodx(N, false);
  vector<bool> goody(M, false);
  for (int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(masu.at(i).at(j) == '#'){
        goodx.at(i) = true;
        goody.at(j) = true;
      }
    }
  }
  
  for (int i =0; i < N; i++){
    if(goodx.at(i)){
      for(int j =0; j < M; j++){
        if(goody.at(j)){
          cout << masu.at(i).at(j);
        }
      }
     cout << endl;
    }
  }
  return 0;
}
