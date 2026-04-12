#include <iostream>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
signed main() {
	int h, w; cin >> h >> w;
	bool a[200], b[200]; char m[200][200];
	for (int j = 0; j < w; j++)b[j] = 1;
	for (int i = 0; i < h; i++){
		a[i] = 1;
		for (int j = 0; j < w; j++) {
			cin >> m[i][j];
			if (m[i][j] == '#') {
				a[i] = 0;
				b[j] = 0;
			}
		}
	}
	a[199] = 0;
	for (int i = 0; i < h; i++) {
		if (a[i])continue;
		for (int j = 0; j < w; j++) {
			if (!b[j])cout << m[i][j];
		}
		cout << endl;
		a[199] = 1;
	}
	if (!a[199])cout << endl;
}