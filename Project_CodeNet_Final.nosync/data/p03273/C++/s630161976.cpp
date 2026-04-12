/*
解き方：
対角成分が黒であれば、その行と列は削られない。
逆に言えば、対角成分が白の場所しか削られない。

*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  char map[101][101] = {};
  int chk[101][101] = {};

  for(int i = 0; i < h; i++){
    scanf("%s", map[i]);
  }

  for(int i=0;i<h;i++) { //横を見る
      bool flag=false;
      //その列に黒があればフラグを立てる
      for(int j=0;j<w;j++) if(map[i][j]=='#') flag=true;
      if(!flag) for(int j=0;j<w;j++) chk[i][j]=true;
  }

  for(int i=0; i < w; i++){ //縦を見る
    bool flag =  false;
    for(int j = 0; j < h; j++) if(map[j][i] == '#') flag = true;
    if(!flag) for(int j = 0; j<h; j++) chk[j][i] =true;
  }

  for(int i=0; i < h; i++){
    bool flag = false;
    for(int j=0; j < w; j++){
      if(!chk[i][j]){ // フラグが立ってないとこをみて
        flag = true;
        printf("%c", map[i][j]);
      }
    }
    if(flag) puts("");
  }


}
