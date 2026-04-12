#include <bits/stdc++.h>

using namespace std;

bool goodh[110], goodw[110];

int main() {
	string board[110];
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == '#') {
				goodh[i] = true;
				goodw[j] = true;
			}
		}
	}
	// cout << "----------------------" << endl;
	for (int i = 0; i < H; i++) {
		if (goodh[i]) {
			for (int j = 0; j < W; j++) {
				if (goodw[j]) {
					cout << board[i][j];
				}
			}
			cout << endl;
		}
	}
}