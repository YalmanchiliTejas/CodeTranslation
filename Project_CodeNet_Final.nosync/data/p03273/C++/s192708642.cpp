#include <iostream>

using namespace std;

const int MAX = 100;

int main() {
	int H, W;
	char grid[MAX][MAX];

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> grid[i][j];
		}
	}

	int x = 0;

	for (int i = 0; i < H; i++,x++) {
		bool check = true;
		for (int j = 0; j < W; j++) {
			if (grid[i][j] == '#')check = false;
		}

		for (int j = 0; j < W; j++) {
			grid[x][j] = grid[i][j];
		}

		if (check)x--;
	}

	H = x;
	x = 0;

	for (int i = 0; i < W; i++,x++) {
		bool check = true;
		for (int j = 0; j < H; j++) {
			if (grid[j][i] == '#')check = false;
		}

		for (int j = 0; j < H; j++) {
			grid[j][x] = grid[j][i];
		}
		if (check)x--;
	}

	W = x;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}