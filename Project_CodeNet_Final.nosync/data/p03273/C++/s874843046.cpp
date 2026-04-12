#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin >> x >>y;
  
  vector<bool> x1(x,false);
  vector<bool> y1(y,false);
  
  vector<vector<char>> v(x,vector<char>(y));
  
  for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
      cin >> v.at(i).at(j);
    }
  }
  
  for(int i=0; i<x;i++){
    for(int j=0; j<y;j++){
      if(!(v.at(i).at(j)=='.'))
        break;
      if(j==y-1)
        x1.at(i)=true;
    }
  }
  
  for(int i=0; i<y;i++){
    for(int j=0;j<x; j++){
      if(!(v.at(j).at(i)=='.'))
        break;
      if(j==x-1)
        y1.at(i)=true;
    }
  }
  
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      if( !( x1.at(i) || y1.at(j) ) )
        cout <<v.at(i).at(j);
    }
    cout << endl;
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
}
