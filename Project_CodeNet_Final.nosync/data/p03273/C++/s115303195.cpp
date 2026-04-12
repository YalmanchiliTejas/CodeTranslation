#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
typedef long long LL;

int main() {

	char c[100][100];
	int h, w;
	bool hoge = true;
	std::cin >> h >> w;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			std::cin >> c[i][j];
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (c[i][j] != '.') {
				hoge = false;
			}
		}
		if (hoge) {
			for (int j = 0; j < w; ++j) {
				c[i][j] = '0';
			}
		}
		hoge = true;
	}

	hoge = true;

	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			if (c[j][i] != '.' && c[j][i] != '0') {
				hoge = false;
			}
		}
		if (hoge) {
			for (int j = 0; j < h; ++j) {
				c[j][i] = '0';
			}
		}
		hoge = true;
	}

	for (int i = 0; i < h; ++i) {
		int temp = 0;
		for (int j = 0; j < w; ++j) {
			if (c[i][j] != '0') {
				std::cout << c[i][j];
			}
			else {
				temp += 1;
			}
		}
		if (temp != w) {
			std::cout << "" << std::endl;
		}
	}

	return 0;
}