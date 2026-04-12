#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  vector<int> B(H), C(W);
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> A.at(i).at(j);
      if(A.at(i).at(j) == '#'){
        B.at(i) = 1;
        C.at(j) = 1;
      }
    }
  }
  
  bool a = false;
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(B.at(i) == 1 && C.at(j) == 1){
        cout << A.at(i).at(j);
        a = true;
      }
    }
    
    if(a){
      cout << endl;
    }
    a = false;
  }

}