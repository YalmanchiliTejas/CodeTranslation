#include <bits/stdc++.h>
using namespace std;

int main() {
  int y,x;
  cin >> y >> x;
  int flag=0;
  
  vector<vector<char>> a(y,vector<char>(x));

  for(int i=0 ; i<y ; i++){
    for(int j=0 ; j<x ; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<int> y_flag(y),x_flag(x);
  
  //横列の出力フラグ
  for(int i=0 ; i<y ; i++){
    int flag=0;

    for(int j=0 ; j<x ; j++){
      if(a.at(i).at(j)=='#'){
        flag++;
        break;
      }
    }
    
    if(flag==1){
    y_flag.at(i)++;
    }
  }

  //縦列の出力フラグ
  for(int j=0 ; j<x ; j++){
    int flag=0;

    for(int i=0 ; i<y ; i++){
      if(a.at(i).at(j)=='#'){
        flag++;
        break;
      }
    }
    
    if(flag==1){
    x_flag.at(j)++;
    }
  }
  
  //出力
  for(int i=0 ; i<y ; i++){
    for(int j=0 ; j<x ; j++){
      if(x_flag.at(j)==1 && y_flag.at(i)==1){
        cout << a.at(i).at(j);
      }
    }
    
    if(y_flag.at(i)==1){
      cout << endl;
    }
  }
}