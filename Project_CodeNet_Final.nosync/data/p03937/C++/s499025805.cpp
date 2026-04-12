#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int H, W;
string a[10];

int main(int argc, char const *argv[]) {
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> a[i];
	char cur = a[0][0];
	int x = 0, y = 0;
	bool flag = false;
	while (true) {
		bool no = false;
		if (x == H-1 && y == W-1) {
			flag = true;
			break;
		}
		if (x+1 < H && a[x+1][y] == '#') {
			a[x][y] = '.';
			for (int i = 0; i < W; i++) {
				if (a[x][i] == '#') {
					no = true;
					break;
				}
			}
			if (no) break;
			x++;
		}
		else if (y+1 < W && a[x][y+1] == '#') {
			a[x][y] = '.';
			for (int i = 0; i < H; i++) {
				if (a[i][y] == '#') {
					no = true;
					break;
				}
			}
			if (no) break;
			y++;
		}
		else break;
	}

	if (flag) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}