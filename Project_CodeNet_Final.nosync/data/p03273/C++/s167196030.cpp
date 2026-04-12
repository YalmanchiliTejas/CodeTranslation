#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main() {
	int H, W;	cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
	}
	vector<vector<bool>> isA(H, vector<bool>(W, 0));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			isA[i][j] = true;
		}
	}
	bool b = false;
	for (int j = 0; j < W; ++j) {
		b = false;
		for (int i = 0; i < H; ++i) {
			if (a[i][j] == '#') {
				b = true;
				break;
			}
		}
		if (!b) {
			for (int i = 0; i < H; ++i) {
				isA[i][j] = false;
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		b = false;
		for (int j = 0; j < W; ++j) {
			if (a[i][j] == '#') {
				b = true;
				break;
			}
		}
		if (!b) {
			for (int j = 0; j < W; ++j) {
				isA[i][j] = false;
			}
		}
	}

	bool isOutput = false;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (isA[i][j]) {
				isOutput = true;
				cout << a[i][j];
			}
		}
		if (isOutput) {
			cout << endl;
		}
		isOutput = false;
	}
	cin >> H;
}