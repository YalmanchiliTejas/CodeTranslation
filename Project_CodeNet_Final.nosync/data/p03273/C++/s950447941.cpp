#include <bits/stdc++.h>
using namespace std;

signed main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		bool flag = true;
		for (int j = 0; j < a[0].size(); ++j) {
			if (a[i][j] == '#') flag = false;
		}
		if (flag) {
			a.erase(a.begin() + i);
			i--;
		}
	}

	for (int j = 0; j < a[0].size(); ++j) {
		bool flag = true;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i][j] == '#') flag = false;
		}
		if (flag) {
			for (int i = 0; i < a.size(); ++i) {
				a[i].erase(a[i].begin() + j);
			}
			j--;
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}

}
