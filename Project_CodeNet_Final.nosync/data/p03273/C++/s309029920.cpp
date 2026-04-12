#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> A(MAX, vector<char>(MAX));
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> A[h][w];
		}
	}
	for (auto h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (A[h][w] == '#') {
				break;
			}
			if (w == W - 1) {
				A.erase(A.begin() + h);
				H--;
				h--;
			}
		}
	}
	for (auto w = 0; w < W; w++) {
		for (int h = 0; h < H; h++) {
			if (A[h][w] == '#') {
				break;
			}
			if (h == H - 1) {
				for (int i = 0; i < H; i++) {
					A[i].erase(A[i].begin() + w);
				}
				W--;
				w--;
			}
		}
	}
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cout << A[h][w];
		}
		cout << endl;
	}
	return 0;
}
