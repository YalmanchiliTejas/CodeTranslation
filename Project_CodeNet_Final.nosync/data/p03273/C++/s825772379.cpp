#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int i = 0; i < H; i++) {
		cin >> A.at(i);
  }

	vector<vector<string>> result(H, vector<string>(W));

	// 行
  for (int i = 0; i < H; i++) {
		int cnt = 0;
	  for (int j = 0; j < W; j++) {
		  result.at(i).at(j) = A.at(i).at(j);
			if(A.at(i).at(j) == '.') cnt++;
  	}
		if(cnt == W){
			for (int j = 0; j < W; j++) {
		  	result.at(i).at(j) = "-";
			}
		}
  }

	// 列
	for (int j = 0; j < W; j++) {
		int cnt = 0;
	  for (int i = 0; i < H; i++){
			if(A.at(i).at(j) == '.') cnt++;
		}
		if(cnt == H){
			for (int i = 0; i < H; i++){
		  	result.at(i).at(j) = "-";
			}
		}
	}

	// 出力
  for (int i = 0; i < H; i++) {
		int cnt = 0;
	  for (int j = 0; j < W; j++) {
			if(result.at(i).at(j) != "-"){
				cout << result.at(i).at(j);
			} else {
				cnt++;
			}
  	}
		if(cnt != W) cout << endl;
  }
}
