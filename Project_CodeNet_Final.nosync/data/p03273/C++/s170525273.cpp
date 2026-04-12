#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	vector<bool> row(h), column(w);

	string a[h];
	for (int i = 0; i < h; i++) {
		cin >> a[i];
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				row[i] = 1;
				break;
			}
		}
	}

	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (a[i][j] == '#') {
				column[j] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (row[i] && column[j])
				cout << a[i][j];
		}
		if (row[i])
			cout << endl;
	}
}
