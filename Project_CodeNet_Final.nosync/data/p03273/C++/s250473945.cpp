#include <bits/stdc++.h>
using namespace std;
int main() {
  int W, H;
  int flg,flg2;
//　配列サイズの読み込み
  cin >> H >> W;
   vector<vector<char>> A(H,vector<char>(W));
//  配列データの読み込み
  for (int i = 0; i < H; i++) {
	for (int j = 0; j < W; j++) {
	  cin >> A.at(i).at(j);
    }
  }
//  配列要素を表示すべきか、横と縦に#があるかをチェック
  for (int i = 0; i < H; i++) {
	flg2 = 0;
    for (int j = 0; j < W; j++) {
    	flg = 0;
      	for (int k = 0; k < H; k++) {
        	if (A.at(k).at(j) == '#') {
          		flg++;
		     	break;
        	}
		}
      	for (int k = 0; k < W; k++) {
        	if (A.at(i).at(k) == '#') {
          		flg++;
		        break;
        	}
	    }
      	if (flg == 2) {
        	cout << A.at(i).at(j);
	        flg2 = 1;
    	}
    }
    if (flg2 == 1) {
		cout << endl;
    }
  }
}