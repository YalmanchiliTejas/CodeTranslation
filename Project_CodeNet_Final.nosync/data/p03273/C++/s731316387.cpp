#include<iostream>
#include<vector>
using namespace std;
int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>>a(h, vector<char>(w));
	vector<int>clear_low, clear_line;
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)cin >> a[i][j];
	for (int i = 0; i < h; i++) {
		bool all_w = true;
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#')all_w = false;
		}
		if (all_w)clear_low.emplace_back(i);
	}
	for (int i = 0; i < w; i++) {
		bool all_w = true;
		for (int j = 0; j < h; j++) {
			if (a[j][i] == '#')all_w = false;
		}
		if (all_w)clear_line.emplace_back(i);
	}
	if (clear_line.size() == 0 && clear_low.size() == 0) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)cout << a[i][j];
			cout << endl;
		}
		return 0;
	}
	int p = 0, q = 0;
	for (int i = 0; i < h; i++) {
		if (i == clear_low[p]) {
			p++;
			continue;
		} else {
			for (int j = 0; j < w; j++) {
				if (j == clear_line[q]) {
					q++;
					continue;
				} else {
					cout << a[i][j];
				}
			}
			cout << endl;
			q = 0;
		}
	}
	return 0;
}