#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, checker;//定義, 入力
  cin >> H >> W;
  vector<vector<char>> result(H, vector<char>(W));
  vector<int> hight(H);
  vector<int> width(W);
  for (int i = 0; i < H; i++)
  for (int j = 0; j < W; j++)
  cin >> result.at(i).at(j);

  for (int i = 0; i < H; i++){//行列探し
    checker = 1;
    for (int j = 0; j < W; j++){
      if (result.at(i).at(j) == '#')
      checker = 0;
    }
    hight.at(i) = checker;
  }

  for (int i = 0; i < W; i++){
    checker = 1;
    for (int j = 0; j < H; j++){
      if (result.at(j).at(i) == '#')
      checker = 0;
    }
    width.at(i) = checker;
  }

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (hight.at(i) == 0 && width.at(j) == 0)
      cout << result.at(i).at(j);
    }
    cout << endl;
  }
}
