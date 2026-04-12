#include<iostream>
#include<string>

using namespace std;

int main() {
	int h, w;
	string a[8], ans = "Possible";
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int c = 0, r = 0, d = 0, l = 0, u = 0;
			if (a[y][x] == '#')c = 1;
			if (y+1 < h || x+1 < w) {
				if (x + 1 < w && a[y][x + 1] == '#')r = 1;
				if (y + 1 < h && a[y + 1][x] == '#')d = 1;
				if (c && !(r^d))ans = "Impossible";
			}
			if (y > 0 || x > 0) {
				if (x - 1 >= 0 && a[y][x - 1] == '#')l = 1;
				if (y - 1 >= 0 && a[y - 1][x] == '#')u = 1;
				if (c && !(l^u))ans = "Impossible";
			}
		}
	}
	cout << ans << endl;
	return 0;
}