#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int H, W;
char a[8][8];
int main() {
	cin >> H >> W;
	int cnt = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
			if (a[i][j] == '#') cnt++;
		}
	}
	if (H + W - 1 == cnt) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}