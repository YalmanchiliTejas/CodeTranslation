#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector< vector<char> > data(H, vector<char>(W));
  // 入力
  for (int i = 0; i < H; i++) {
    string rowText;
    cin >> rowText;
    // i番目の状態を読む
    for (int j = 0; j < W; j++) {
      data.at(i).at(j) = rowText.at(j);
    }
  }
  vector<int> shouldVec(H);
    // 削除するべき列を探す
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '#') {
        shouldVec.at(i) = 1;
        break;
      }
    }
    if (shouldVec.at(i) == 1) {
      continue;
    } else {
      shouldVec.at(i) = 0;
    }
  }
  
  // 削除するべき列を削除する
  int removeHCount = 0;
  for (int i = 0; i < H; i++) {
    if (shouldVec.at(i) == 0) {
      data.erase(data.begin() + i - removeHCount);
      removeHCount += 1;
    }
  }
  
  vector<int> shouldWVec(W);
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < data.size(); j++) {
      if (data.at(j).at(i) == '#') {
        shouldWVec.at(i) = 1;
        break;
      }
      if (data.size() == j + 1) {
        // 削除するべき列
        shouldWVec.at(i) = 0;
      }
    }
  }
  int dataSize = data.size();
  // 削除するべき列を削除する
  bool ifBeforeDeleted = false;
  int removeCount = 0;
  for (int i = 0; i < shouldWVec.size(); i++) {
    if (shouldWVec.at(i) == 0) {
      for (int j = 0; j < dataSize; j++) {
        data.at(j).erase(data.at(j).begin() + i - removeCount);
      }
      removeCount += 1;
    }
  }
  
  // 答えを出力する
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data.at(i).size(); j++) {
      cout << data.at(i).at(j);
    }
    cout << endl;
  }
}
                           