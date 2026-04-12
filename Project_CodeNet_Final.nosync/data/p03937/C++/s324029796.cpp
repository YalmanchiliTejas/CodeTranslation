#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cassert>
#include <deque>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

string a[8];

//#define LOCAL_DEBUG
int main() {
#ifdef LOCAL_DEBUG
	freopen("input.txt","r", stdin);
#endif
	int H, W;
	cin >> H >> W;

	int scnt = 0;
	for (int i = 0; i < H; i++) {
		cin >> a[i];
		for (int j = 0; j < W; j++)
			if (a[i][j] == '#') scnt++;
	}

	int x, y;
	x = y = 0;

	int cnt = 1;
	while (true) {
		if (x == W - 1 && y == H - 1) {
			if (scnt == cnt)
				cout << "Possible" << endl;
			else
				cout << "Impossible" << endl;
			break;
		}
		if (x + 1 < W && a[y][x  + 1] == '#') {
			x++;
			cnt++;
			continue;
		}
		if (y + 1 < H && a[y + 1][x] == '#') {
			y++;
			cnt++;
			continue;
		}
		cout << "Impossible" << endl;
		break;
	}

	return 0;
}
