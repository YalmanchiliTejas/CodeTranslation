#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define sp ' '
using namespace std;

int H, W, x, y;
bool b;
string A[8];

int main(){
	cin >> H >> W;
	for (int i = 0; i != H; ++i)
		cin >> A[i];
	b = true;
	if (A[0][0] == '.') {
		cout << "Impossible" << endl;
		return 0;
	}
	A[0][0] = '.';
	while (b) {
		b = false;
		if (x != H-1) {
			if (A[x + 1][y] == '#') {
				++x;
				A[x][y] = '.';
				b = true;
				continue;
			}
			if (y != W-1) {
				if (A[x][y + 1] == '#') {
					++y;
					A[x][y] = '.';
					b = true;
					continue;
				}
			}
		}
		if (y != W-1) {
			if (A[x][y + 1] == '#') {
				++y;
				A[x][y] = '.';
				b = true;
				continue;
			}
		}
	}
	b = true;
	if (x != H-1 || y != W-1)
		b = false;
	for (int i = 0; i != H; ++i) {
		for (int j = 0; j != W; ++j) {
			if (A[i][j] == '#') {
				b = false;
			}
		}
	}
	if (b) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}