#include<bits/stdc++.h>
using namespace std;



int main(){
  int i,j;
  int H, W; // 入力用整数
  cin >> H >> W;
  // 入力用 Bool型 2次元配列
  bool ** arr = new bool *[H];
  for(i = 0;i < H;i++){
    arr[i] = new bool[W];
  }
  // 黒が出てきたか記録
  bool *xs = new bool[H];
  bool *ys = new bool[W];
  // 初期化
  for(i = 0;i < H;i++){
    xs[i] = false;
  }
  for(i = 0;i < W;i++){
    ys[i] = false;
  }

  char s;
  for(i = 0;i < H;i++){
    for(j = 0;j < W;j++){
      cin >> s;
      if(s == '.'){ // (i, j) が白の場合
        arr[i][j] = false;
      }
      else{ // (i, j) が黒の場合
        arr[i][j] = true;
        xs[i] = true; // xsに記録
        ys[j] = true; // ysに記録
      }
    }
  }
  for(i = 0;i < H;i++){
    if(xs[i]){ // 黒がある場合(消されないもの)
      for(j = 0;j < W;j++){
        if(ys[j]){ // 黒がある場合(消されないもの)
          if(arr[i][j]){
            cout << '#';
          }
          else{
            cout << '.';
          }
        }
      }
      cout << endl;
    }
  }
  return 0;
}