#include "bits/stdc++.h"
using namespace std;

int main()
{
	int H, W;
	cin.tie(0);	ios::sync_with_stdio(false);
	cin >> H >> W;

	vector<vector<char>> b(H, vector<char>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> b[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < H; ++i) {
		bool tf = true;
		for (int j = 0; j < W; ++j) {
			tf = tf && (b[i][j] == '.');
		}
		if (tf) {
			for (int j = 0; j < W; ++j) {
				b[i][j] = 'X';
			}
		}
	}
	for (int j = 0; j < W; ++j) {
		bool tf = true;
		for (int i = 0; i < H; ++i) {
			tf = tf && (b[i][j] == '.' || b[i][j] == 'X');
		}
		if (tf) {
			for (int i = 0; i < H; ++i) {
				b[i][j] = 'X';
			}
		}
	}
	for (auto& l : b) {
		bool tf = true;
		for (auto& r : l) {
			tf = tf && (r == 'X');
		}
		if (!tf) {
			for (auto& r : l) {
				if (r != 'X')
					cout << r;
			}
			cout << endl;
		}
	}
}