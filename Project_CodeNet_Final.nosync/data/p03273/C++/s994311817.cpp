#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> vec(H); //stringは配列として使える！！
  for (int i = 0; i < H; i++){
    cin >> vec.at(i);
  }
  
  vector<bool> row(H,false);
  vector<bool> col(W,false);
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (vec[i][j] == '#'){//一つでも＃が含まれていたらそのrow・colはtrueにする
        row[i] = true;
        col[j] = true;
      }
    }
  }
  
  for (int i = 0; i < H; i++){
    if (row[i]){
      for (int j = 0; j < W; j++){
        if (col[j])
          cout << vec[i][j];
      }
    cout << endl;
    }
  }
}
