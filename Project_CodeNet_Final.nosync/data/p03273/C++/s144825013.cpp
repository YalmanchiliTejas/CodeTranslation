#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w; cin >> h >> w;

	vector<vector<char>> c(h + 2, vector<char>(w + 2, '-1'));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> c[i][j];
		}
	}

	vector<bool>isWhiteRow(h + 2, true);
	vector<bool>isWhiteColumn(w + 2, true);

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (c[i][j] == '#') isWhiteRow[i] = false;
		}
	}

	for (int j = 1; j <= w; j++) {
		for (int i = 1; i <= h; i++) {		
			if (c[i][j] == '#') isWhiteColumn[j] = false;
		}
	}

	for (int i = 1; i <= h; i++) {
		if (isWhiteRow[i]) continue;
		for (int j = 1; j <= w; j++) {
			if (isWhiteColumn[j]) continue;
			cout << c[i][j];
		}
		cout << endl;
	}

	return 0;
}