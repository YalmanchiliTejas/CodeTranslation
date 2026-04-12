#include "bits/stdc++.h"
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>>A(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A.at(i).at(j);
		}
	}
	for (int i = 0; i < H; i++) {
		int num = 0;
		for (int j = 0; j < W; j++) {
			if (A.at(i).at(j) == '#') num++;
		}
		if (num == 0) {
			for (int j = 0; j < W; j++) {
				A.at(i).at(j) = 'X';
			}
		}
	}
	for (int i = 0; i < W; i++) {
		int num = 0;
		for (int j = 0; j < H; j++) {
			if (A.at(j).at(i) == '#') num++;
		}
		if (num == 0) {
			for (int j = 0; j < H; j++) {
				A.at(j).at(i) = 'X';
			}
		}
	}
	for (int i = 0; i < H; i++) {
		int num = 0;
		for (int j = 0; j < W; j++) {
			if (A.at(i).at(j) != 'X') cout << A.at(i).at(j);
			else num++;
		}
		if (num != W) cout << endl;
	}
}