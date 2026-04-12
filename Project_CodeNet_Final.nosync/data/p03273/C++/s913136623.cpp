#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int main() {
	char grid[110][110];
	int h, w;
	cin >> h >> w;
	int count = 0;
	int endline[110];
	for (int i = 0; i < 110; i++) {
		endline[i] = 1;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == '.') {
				count++;
			}
		}
		if (count == w) {
			for (int j = 0; j < w; j++) {
				grid[i][j] = '0';
			}
			endline[i] =0;
		}
		count = 0;
	}
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (grid[i][j] == '.' || grid[i][j] == '0') {
				count++;
			}
		}
		if (count == h) {
			for (int i = 0; i < h; i++) {
				grid[i][j] = '0';
			}
		}
		count = 0;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] != '0') {
				cout << grid[i][j];
			}
		}
		if (endline[i] == 1) {
			cout << endl;
		}
	}
	return 0;
}