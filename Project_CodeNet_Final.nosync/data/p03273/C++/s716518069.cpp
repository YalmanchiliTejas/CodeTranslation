#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int h, w; cin >> h >> w;
	vector<vector<char>> a(h + 2, vector<char>(w + 2));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> a[i][j];
		}
	}
	vector<bool> deleteRow(h, true);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (a[i][j] == '#') deleteRow[i - 1] = false;
		}
	}
	vector<bool> deleteColumn(w, true);
	for (int j = 1; j <= w; j++) {
		for (int i = 1; i <= h; i++) {
			if (a[i][j] == '#') deleteColumn[j - 1] = false;
		}
	}
	for (int i = 1; i <= h; i++) {
		if (deleteRow[i - 1]) continue;
		for (int j = 1; j <= w; j++) {
			if (deleteColumn[j - 1]) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}