#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> A(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  
  vector<bool> row(H, false); //白しかない状態をfalse、1つでも黒があればtrueとするbool値
  vector<bool> col(W, false); //同上
  
  for (int i = 0; i < H; i++) { //二重ループで各要素を見ていき、黒があればi行とj列のboolはtrueに変更する
  	for (int j = 0; j < W; j++) {
		if (A.at(i).at(j) == '#') {
			row.at(i) = true;
			col.at(j) = true;
        }
    }
  }
      
  for (int i = 0; i < H; i++) {
	if (row.at(i)) { // i行目がtrueの場合
		for (int j = 0; j < W; j++) {
			if (col.at(j)) { // j列目がtrueの場合
				cout << A.at(i).at(j); // 出力する
            }
        }
		cout << endl;
    }
  }
}