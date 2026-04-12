#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> M(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j=0 ; j < W ; j++){
      cin >> M[i][j];
    }
  }

  //行のチェック
  vector<int> h(1,-1);
  for(int i = 0; i < H ; i++){
    int check = 0;
    for(int j = 0; j < W  ; j++){
      if(M[i][j] == '.'){
        check++;
      }
    }
    if(check == W){
      h.push_back(i);
    }
  }
  
  //for(x:h){
    //cout << x;
  //}
  //cout << endl;
  //列のチェック
  vector<int> w(1,-1);
  for(int i = 0; i < W ; i++){
    int check = 0;
    for(int j = 0; j < H ; j++){
      if(M[j][i] == '.'){
        check++;
      }
    }
    if(check == H){
      w.push_back(i);
    }
  }
  //for(x:w){
    //cout << x;
  //}
  //cout << endl;
  //cout << w.at(2) << endl;

  bool flag = true;
  for (int i = 0; i < H; i++) {
    flag = true;
    for(int k=0 ; k<h.size() ; k++){
      int x = h[k];
        if(i==x){
          flag = false;
          break;
        }
    }
    if(flag == false){
      continue;
    }
    
    for (int j=0 ; j < W ; j++){
      flag = true;
      for(int k=0 ; k <w.size() ; k++){
        int x = w[k];
        if(j==x){
          flag = false;
          break;
        }
      }      
      if(flag == true){
        cout << M[i][j];
      }
      
      /*
      if(j >= w.at(2)){
        cout << endl;
      }
      */
    }
    cout << endl;
  }
  
}
