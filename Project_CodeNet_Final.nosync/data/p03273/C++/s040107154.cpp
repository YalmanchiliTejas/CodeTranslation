#include <bits/stdc++.h>
using namespace std;

int main() {
	//マス目数を取得。縦はH、横はW
	int H, W;
	cin >> H >> W;

	//マスの色を入力。白なら'.'、黒なら'#'
	vector<vector<char>> trout(H, vector<char>(W));
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> trout.at(i).at(j);
		}
	}

	//マス目を圧縮して出力
	//縦の白マスを検出
	vector<int> Hwhite(W, -1);
	for(int i = 0; i < W; i++){
		int white = 0;
		for(int j = 0; j < H; j++){
			if(trout.at(j).at(i) == '#') break;
			white++;
		}
		if(white == H)
			Hwhite.at(i) = i;
	}
	//横の白マスを検出
	vector<int> Wwhite(H, -1);
	for(int i = 0; i < H; i++){
		int white = 0;
		for(int j = 0; j < W; j++){
			if(trout.at(i).at(j) == '#') break;
			white++;
		}
		if(white == W)
			Wwhite.at(i) = i;
	}

	for(int i = 0; i < H; i++){
		//横がすべて白なら次に行く
		if(Wwhite.at(i) == i)
			continue;
		for(int j = 0; j < W; j++){
			//（縦の要素が）白なら描画しない
			if(Hwhite.at(j) == j)
				continue;
			else
				cout << trout.at(i).at(j);
		}
		cout << endl;
	}
}