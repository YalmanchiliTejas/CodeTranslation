#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	char grid[h][w];
	bool c[h][w];
	for (int i = 0;i < h;i++) {
		bool a = false;
		for (int j = 0;j < w;j++) {
			cin >> grid[i][j];
			if (grid[i][j] == '#')a = true;
		}
		for (int j = 0;j < w;j++) {
			c[i][j] = a;
		}
	}
	for (int j = 0;j < w;j++) {
		bool b = false;
		for (int i = 0;i < h;i++) {
			if (grid[i][j] == '#')b = true;
		}
		for (int i = 0;i < h;i++) {
			if (c[i][j] == true)c[i][j] = b;
		}
	}
	for (int i = 0;i < h;i++) {
		bool d = false;
		for (int j = 0;j < w;j++) {
			if (c[i][j]) {
				cout << grid[i][j];
				if (d == false)d = true;
			}
		}
		if (d)cout << endl;
	}
}