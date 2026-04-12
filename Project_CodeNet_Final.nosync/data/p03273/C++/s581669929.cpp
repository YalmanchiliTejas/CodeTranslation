#include <iostream>
#include <vector>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;

  vector<string> str(H);

  for(int i = 0; i < H; i++){
    cin >> str.at(i);
  }

  vector<bool> row(H, false);
  vector<bool> cell(W, false);

  // 「#」のある行と列をチェック
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(str.at(i).at(j) == '#'){
        row.at(i) = true;
        cell.at(j) = true;
      }
    }
  }

  // チェックの入った行と列の交差するセルは「#」を表示
  for(int i = 0; i < H; i++){
    if(row.at(i)){
      for(int j = 0; j < W; j++){
        if(cell.at(j)){
          cout << str.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  
}


