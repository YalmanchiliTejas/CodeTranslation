#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define int long long
bool h_[200], w_[200];
signed main() {
	int h, w; cin >> h >> w;
	char map[200][200];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				h_[i] = 1;
				w_[j] = 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		bool p=0;
		for (int j = 0; j < w; j++) {
			if (h_[i] && w_[j]) {
				cout << map[i][j];
				p = 1;
			}
		}
		if (p)cout << endl;
	}
}