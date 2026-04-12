#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int h, w;
char a[8][10];

int main() {
	int i, j;
	
	cin >> h >> w;
	for (i = 0; i < h; i++) cin >> a[i];
	
	for (i = 1; i < h; i++) {
		for (j = 0; j < w; j++) { if (a[i][j] == '#') break; } int l = j;
		for (j = w - 1; j >= 0; j--) { if (a[i-1][j] == '#') break; } int r = j;
		if (l < r) { cout << "Impossible" << endl; return 0; }
	}
	cout << "Possible" << endl;
	return 0;
}