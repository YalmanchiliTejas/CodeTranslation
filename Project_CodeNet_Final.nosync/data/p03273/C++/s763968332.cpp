// --https://kenkoooo.com/atcoder/#/table/soma62jp
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {

	int H, W, cnt, cnt2, flg, i, j, k;
	string a[100];
	string b[100];
	char c[100][101] = {0};

	cin >> H >> W;

	for (i = 0; i < H; i++) {
		cin >> a[i];
	}

	cnt = 0;
	for (i = 0; i < H; i++) {
		flg = 0;
		for (j = 0; j < W; j++) {
			if (a[i][j] == '#') {
				flg = 1;
				break;
			}
		}
		if (flg) {
			b[cnt] = a[i];
			cnt++;
		}
	}

	cnt2 = 0;
	for (j = 0; j < W; j++) {
		flg = 0;
		for (i = 0; i < cnt; i++) {
			if (b[i][j] == '#') {
				flg = 1;
				break;
			}
		}
		if (flg) {
			for (i = 0; i < cnt; i++) {
				c[i][cnt2] = b[i][j];
			}
			cnt2++;
		}
		else {

		}
	}

	for (i = 0; i < cnt; i++) {
		cout << c[i] << endl;
	}

	return 0;

}
