#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define MAX 100
int is[MAX];
int h, w;
string s[8];
bool judge() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == '#') {
				if (i != 0 && j != 0) {
					if (s[i - 1][j] == '#' && s[i][j - 1] == '#') {
						return false;
					}
				}
				if (i < h - 1 && j > 0) {
					if (s[i + 1][j - 1] == '#' && s[i][j - 1] == '#') {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(void) {
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		cin >> s[i];
	}
	bool f = judge();
	cout << (f ? "Possible" : "Impossible") << endl;
	return 0;
}