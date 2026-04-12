#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  if(S.at(0)=='A' && S.at(1)=='A' && S.at(2)=='A'){
    cout << "No" << endl;
  }
  else if (S.at(0)=='B' && S.at(1)=='B' && S.at(2)=='B'){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
  
  
}

  
  

  
  // int型の2次元配列(3×4要素の)の宣言
  //vector<vector<int>> data(3, vector<int>(4));

  // 入力 (2重ループを用いる)
  //for (int i = 0; i < 3; i++) {
    //for (int j = 0; j < 4; j++) {
      //cin >> data.at(i).at(j);
    //}
  //}
