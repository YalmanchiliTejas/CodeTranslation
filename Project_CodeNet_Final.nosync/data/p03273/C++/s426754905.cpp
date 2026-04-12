#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, w; cin >> n >> w;
	vector<vector<char>> a(n, vector<char>(w));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	vector<bool> rowBlackExist(n, false);
	vector<bool> columnBlackExist(w, false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				rowBlackExist[i] = true;
				columnBlackExist[j] = true;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (rowBlackExist[i]) {
			for (int j = 0; j < w; j++) {
				if (columnBlackExist[j]) cout << a[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}