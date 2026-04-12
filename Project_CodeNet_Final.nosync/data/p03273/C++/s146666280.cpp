#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}

	vector<bool> hh(h, false);
	vector<bool> ww(w, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				hh[i] = true;
				ww[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (hh[i]) {
			for (int j = 0; j < w; j++) {
				if (ww[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}