#include <iostream>
#include <string>

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	string *row;
	row = new string[H];

	//1行全部圧縮できるか
	for (int i = 0; i < H; i++) {
		cin >> row[i];
		for(int t = 0; t < W; t++) {
			if (row[i][t] != '.') break;
			if (t == W - 1) {
				i--;
				H--;
			}
		}
	}

	for(int t = 0; t < W; t++) {
		for (int i = 0; i < H; i++) {
			if(row[i][t] != '.') break;
			if (i == H - 1) {
				for (int i = 0; i < H; i++) {
					row[i].erase(row[i].begin() + t);
				}
				t--;
				W--;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		cout << row[i] << endl;
	}
}

