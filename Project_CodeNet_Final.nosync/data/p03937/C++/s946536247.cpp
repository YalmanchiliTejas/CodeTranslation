#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;


int main() {
	int H, W;
	cin >> H >> W;
	int a[8][8];
	int count = 0;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			char c; cin >> c;
			if (c == '#') { count++; }
		}
	}

	if (count == H + W - 1) {
		cout << "Possible";
	}
	else {
		cout << "Impossible";
	}
	return 0;
}