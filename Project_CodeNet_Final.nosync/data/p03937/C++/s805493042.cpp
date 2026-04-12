#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int h, w;

	cin >> h >> w;
	vector<string> a(h);
	vector<string> b(h, string(w, '.'));
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}

	b[0][0] = '#';
	int x = 0;
	int y = 0;

	int dx[2] = {1, 0};
	int dy[2] = {0, 1};

	while(1) {
		bool update = false;
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < w && ny < h && a[ny][nx] == '#') {
				b[ny][nx] = '#';
				x = nx;
				y = ny;
				update = true;
				break;
			}
		}
		if (x == w - 1 && y == h - 1) {
			break;
		}
		if (!update) {
			break;
		}

	}

	string ans = "Possible";
	for (int i = 0; i < h; i++) {
		if (a[i] != b[i]) {
			ans = "Impossible";
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
