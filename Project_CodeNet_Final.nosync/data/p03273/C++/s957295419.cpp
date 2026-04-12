#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<tuple>
#include<string>
using namespace std;

static const int MAX_H = 110, MAX_W = 110;

int main(void){
  int H, W;
  char a[MAX_H][MAX_W];
  //入力
  cin >> H >> W;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < H; i++){
    bool isColAllDot = true;
    for(int k = 0; k < W; k++){
      if(a[i][k] == '#'){
        isColAllDot = false;
        break;
      }
    }
    for(int j = 0; j < W; j++){
      if(a[i][j] == '#') cout << a[i][j];
      //.の時はその一列とその一行を検索して，どちらかが全て.なら出力しない。
      else{
        bool isRowAllDot = true;
        for(int k = 0; k < H; k++){
          if(a[k][j] == '#'){
            isRowAllDot = false;
            break;
          }
        }
        if(!isColAllDot && !isRowAllDot) cout << a[i][j];
      }
    }
    if(!isColAllDot) cout << endl;
  }
  return 0;
}
