#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(H, vector<char>(W, 'a'));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> map.at(i).at(j);
    }
  }
  //ここまで入力
  
  vector<vector<char>> mapA(H, vector<char>(W, 'a'));
  int height = 0;
  //行を削る表を作る
  
  for (int i = 0; i < H; i++) {
    bool A = false;
    
    for (int j = 0; j < W; j++) {

      if (map.at(i).at(j) == '#') {
        A = true;
        break;
      }
      //もしi+1行に1つでも黒があれば実行する
    }
    
    if (A) {
      mapA.at(height) = map.at(i);
      height++;
    }
  }
  
  vector<vector<char>> mapB(H, vector<char>(W, 'a'));
  int width = 0;
  //列を削る表を作る
  
  for (int i = 0; i < W; i++) {
    bool B = false;
    
    for (int j = 0; j < height; j++) {
      if (mapA.at(j).at(i) == '#') {
        B = true;
        break;
      }
      //もしi+1列に1つでも黒があれば実行する
    }
    
    if (B) {
      for (int k = 0; k < height; k++) {
        mapB.at(k).at(width) = mapA.at(k).at(i);
      }
      width++;
    }  
  }
  //圧縮が終了する
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << mapB.at(i).at(j);
      if (j == width - 1) {
        cout << endl;
      }
    }
  }
}