#include <bits/stdc++.h>
using namespace std;


int main() {
	int H, W;
	cin >> H >> W;
	vector<string> grid(H);
	vector<int> row(0);
	vector<int> column(0);

	//入力情報の保存
	for (int i = 0; i < H; i++) {
			cin >> grid.at(i);
	}

	//#がある行および列は削除されないが、同時に処理するのはやや面倒
	//分けて考える

	//#が存在する行番号を配列rowに保存
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (grid.at(i).at(j) == '#') {
				row.push_back(i);
				break;
			}
		}
	}

	//#が存在する列番号を配列columnに保存
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (grid.at(j).at(i) == '#') {
				column.push_back(i);
				break;
			}
		}
	}

        //#が存在する行と列部分を出力
	for (int i : row) {
		for (int j : column) {
			cout << grid.at(i).at(j);
		}
		cout << endl;
	}

}
