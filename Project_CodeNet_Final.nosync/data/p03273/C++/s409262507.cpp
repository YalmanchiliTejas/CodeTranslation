#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,w;
  cin >> h >> w;
  char data[h][w];
  int count=0;
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      cin >> data[i][j];
    }
  }
  //i行目の調査
  for (int i=0;i<h;i++){
    count=0;
    for (int j=0;j<w;j++){
      if (data[i][j] == '.') count++;
    }
    //i行目を調査して全部空白ならその行をxにする
    if (count == w){
      for (int k=0;k<w;k++){
        data[i][k] = 'x';
      }
    }
  }
  //j列目の調査
  for (int j=0;j<w;j++){
    count=0;
    for (int i=0;i<h;i++){
      if (data[i][j] == '.' || data[i][j] == 'x') count++;
    }
    //j列目を調査して全部空白ならその行をxにする
    if (count == h){
      for (int k=0;k<h;k++){
        data[k][j] = 'x';
      }
    }
  }
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      if (data[i][j] != 'x') cout << data[i][j]; 
    }
    cout << endl;
  }
}