#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	vector<vector<char>> a(h, vector<char>(w, '.'));
	vector<bool> h_bool(h, true);
	vector<bool> w_bool(w, true);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				h_bool[i] = false;
			}
		}
	}

	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (a[i][j] == '#') {
				w_bool[j] = false;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (h_bool[i]) {
				break;
			}
			else if (w_bool[j]) {
			}
			else {
				cout << a[i][j];
			}
		}
		if (!h_bool[i]) {
			cout << endl;
		}
	}


	return 0;
}