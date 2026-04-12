#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  // char型の2次元配列(H×W要素の)の宣言, dataに読み込み
  vector<vector<char>> data(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  vector<int> cvec = {};
  vector<int> rvec = {};
  
  for (int i = 0; i < H; i++) {
    int ccheck = 0;
    for (int j = 0; j < W; j++) {  
      if (data.at(i).at(j) == '#') {
        ccheck += 1; // #を含む行をマークする  
      }
    }
    
    if (ccheck){
        cvec.push_back(i); // #を含む行番号をrvecに追加していく
    }
    
  }
  
  for (int j = 0; j < W; j++) {
    int rcheck = 0;
    for (int i = 0; i < H; i++) {
      if (data.at(i).at(j) == '#') {
        rcheck += 1; // #を含む行をマークする  
      }
    }
    
    if (rcheck){
        rvec.push_back(j); // #を含む行番号をcvecに追加していく
    }
    
  }
  
  /*
  for (c:cvec){
    cout << c;
  }
  cout << endl;
  
  for (r:rvec){
    cout << r;
  }
  */
  
  
  for (c : cvec){
    for (r : rvec){
      cout << data.at(c).at(r);
      if (r == rvec.at(rvec.size()-1)){
        cout << endl;
      }
    }
  }
  
  
}
