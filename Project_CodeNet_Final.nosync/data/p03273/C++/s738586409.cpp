#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> map(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cin >> map.at(i).at(j);
	}
	vector<int> tate(W), yoko(H);
	bool kienai = false;
	for (int i = 0; i < H; i++) {
		kienai = false;
		for (int j = 0; j < W; j++) {
			if (map.at(i).at(j) == '#') {
				kienai = true;
				break;
			}
		}
		if (kienai == false) yoko.at(i)++;
	}
	for (int i = 0; i < W; i++) {
		kienai = false;
		for (int j = 0; j < H; j++) {
			if (map.at(j).at(i) == '#') {
				kienai = true;
				break;
			}
		}
		if (kienai == false) tate.at(i)++;
	}
	for (int i = 0; i < H; i++) {
		if (yoko.at(i) == 1) continue;
		for (int j = 0; j < W; j++) {
			if (tate.at(j) == 0) cout << map.at(i).at(j);
		}
		cout << endl;
	}
}