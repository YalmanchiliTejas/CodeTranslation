#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

char s[110][110];
bool gx[110], gy[110];
int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				gx[j] = true;
				gy[i] = true;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		if (gy[i]) {
			for (int j = 0; j < w; j++) {
				if (gx[j]) {
					cout << s[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}