#include <iostream>
#include <vector>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;

  vector<vector<char>> data(H,vector<char>(W)); // データ
  vector<vector<char>> workA(H,vector<char>(W));// 作業用
  vector<vector<char>> workB(H,vector<char>(W));// 最終用

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> data.at(i).at(j);
    }
  }

  bool flag;
  // dataが横１行すべて「.」なら削除してworkAにコピーする
  int y = 0;
  for(int i = 0; i < H; i++){
    flag = true;
    for(int j = 0; j < W; j++){
      if(data.at(i).at(j) == '#'){
        flag = false;
        break;
      } 
    }
    if(!flag){
      for(int j = 0; j < W; j++){
        char tmp = data.at(i).at(j);
        workA.at(y).at(j) = tmp;
      }
      y++;
    }
  }

// workAが縦１行すべて「.」なら削除してworkBにコピーする
int x = 0;
for(int i = 0; i < W; i++){
    flag = true;
    for(int j = 0; j < y; j++){
      if(workA.at(j).at(i) == '#'){
        flag = false;
        break;
      } 
    }
    if(!flag){
      for(int j = 0; j < y; j++){
        char tmp = workA.at(j).at(i);
        workB.at(j).at(x) = tmp;
      }
      x++;
    }
  }

  //cout << endl;
  for(int i = 0; i < y; i++){
    for(int j = 0; j < x; j++){
      cout << workB.at(i).at(j);
    }
    cout << endl;
  }

}