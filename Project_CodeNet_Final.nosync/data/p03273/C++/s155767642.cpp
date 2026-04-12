#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  //vector<vector<char>> before(H,vector<char>(W));
  vector<string> before(H);
  
  for(int i = 0 ; i < H ; i++){
    cin >> before.at(i);
  }
  
  vector<int> H_num(0);
  vector<int> W_num(0);
  
  for(int i = 0 ; i < H ; i++){
    bool flag = true;
    for(int j = 0 ; j < W ; j++){
      if(before.at(i).at(j) == '#'){
        flag = false;
        break;
      }
    }
    if(!flag){
      H_num.push_back(i);
    }
  }
  
  for(int i = 0 ; i < W ; i++){
    bool flag = true;
    for(int j = 0 ; j < H ; j++){
      if(before.at(j).at(i) == '#'){
        flag = false;
        break;
      }
    }
    if(!flag){
      W_num.push_back(i);
    }
  }
  
  for(int i = 0 ; i < H_num.size() ; i++){
    for(int j = 0 ; j < W_num.size() ; j++){
      cout << before.at(H_num.at(i)).at(W_num.at(j));
    }
    cout << endl;
  }
  
}
