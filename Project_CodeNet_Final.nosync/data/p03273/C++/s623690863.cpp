#include <iostream>
#include <string>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	char a[110][110];
	char yl[110] = { 0 };
	char xl[110] = { 0 };

	for (int y = 0; y < h; y++) {
		cin >> a[y];
		for (int x = 0; x < w; x++) {
			char c = a[y][x];
			if (yl[y] == 0) {
				yl[y] = c;
			}
			if (xl[x] == 0) {
				xl[x] = c;
			}
			if (yl[y] != c) {
				yl[y] = 'Z';
			}
			if (xl[x] != c) {
				xl[x] = 'Z';
			}
		}
	}
	bool ff = false;
	for (int y = 0; y < h; y++) {
		ff = false;
		if (yl[y] == '.') continue;
		for (int x = 0; x < w; x++) {
			if (xl[x] == '.') continue;
			cout << a[y][x];
		}
		ff = true;
		cout << endl;
	}
	if(!ff)
		cout << endl;
}