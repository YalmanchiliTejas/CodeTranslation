#include <algorithm>
#include <array>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;

void Show(vector<vector<bool>> S) {
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S[i].size(); j++) {
			if ((S[i][j])) {
				cout << '.';
			} else {
				cout << '#';
			}
		}
		cout << endl;
	}
}

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<bool>> Grid;
	vector<vector<bool>> Answer;
	char  current;
	for (int i = 0; i < H; i++) {
		vector<bool> Row;
		bool Same = true;
		Row.resize(W);
		for (int j = 0; j < W; j++) {
			cin >> current;
			if (current != '.')Same = false;
			Row[j] = current == '.';
		}
		if (!Same)Grid.push_back(Row);
	}
	H = Grid.size();
	for (int j = 0; j < W; j++) {
		vector<bool> Col;
		Col.resize(H);
		bool Same = true;
		bool  current;
		for (int i = 0; i < H; i++) {
			current = Grid[i][j];
			if (!current)Same = false;
			Col[i] = current;
		}
		if (!Same)Answer.push_back(Col);
	}
	W = Answer.size();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (Answer[j][i]) {
				cout << '.';
			} else {
				cout << '#';
			}
		}
		cout << endl;
	}
//	Show(Grid);
}