#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int H, W; cin >> H >> W;
	char board[8][8];
	int num_sharp = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
			if (board[i][j] == '#') {
				num_sharp++;
			}
		}
	}

	if (num_sharp != W + H - 1) {
		cout << "Impossible" << endl;
		return 0;
	}


	string s = "";
	for (int i = 0; i < H-1; i++) {
		s += 'D';
	}
	for (int i = 0; i < W-1; i++) {
		s += 'R';
	}

	do {
		int i = 0;
		int j = 0;
		for (int k = 0; k < H + W; k++) {
			if (s[k] == 'D') {
				i++;
			}
			else {
				j++;
			}
			if (board[i][j] == '.') {
				break;
			}
			if (k == H + W - 3) {
				cout << "Possible" << endl;
				return 0;
			}
		}
	} while (next_permutation(s.begin(), s.end()));


	cout << "Impossible" << endl;
	return 0;
}