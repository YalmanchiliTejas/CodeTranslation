#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
    cin >> data.at(i).at(j);
    }
  }
  
  int x =0; //answerの列の個数
  for (int i = 0; i < W; i++) {
    bool flag = false;
    for (int j = 0; j < H; j++) {
      if (data.at(j).at(i) == '#')  {/*1列の中に#があったらループを抜けて次の列へ*/
        x++;
        flag = true;
        break;
      }
    }
    if (flag == false) {/*1列の中に#がなかったので全てを-に変える*/
        for (int k = 0; k < H; k++) {
          data.at(k).at(i) = '-';
        }
    }
  }
  
  int y=0;//answerの行の個数
  for (int i = 0; i < H; i++) {
    bool flag = false;
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '#') {/*1行の中に#があったらループを抜けて次の行へ*/
        y++;
        flag = true;
        break;
      }  
    }
    if (flag == false) {/*1行の中に#がなかったので全てを-に変える*/
        for (int k = 0; k < W; k++) {
          data.at(i).at(k) = '-';
        }
    }
  }
  vector<char> henkan = {};//二次元配列dataの中で-だけ除いた値を1次元配列henkanに代入
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) != '-') {
        henkan.push_back(data.at(i).at(j));
      }
    }
  }
  
  vector<vector<char>> answer(y, vector<char>(x));//1次元配列henkanの値を二次元配列に代入
  for (int i=0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      answer.at(i).at(j) = henkan.at(i*x+j);
      cout << answer.at(i).at(j);
      if (j == (x-1)) {
        cout << endl; // 末尾なら改行
      } 
    }
  }
}