#include <bits/stdc++.h>

using namespace std;

char a[11][11];

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= m;j ++) {
			cin >> a[i][j];
			if (a[i][j] != '#' || (i == 1 && j == 1)) continue;
			if (a[i - 1][j] == '#' && a[i][j - 1] == '#') {
				cout << "Impossible";
				return 0;
			}
			if (a[i - 1][j] != '#' && a[i][j - 1] != '#') {
				cout << "Impossible";
				return 0;
			}
		}
	}
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= m;j ++) {
			if (a[i][j] != '#') continue;
			if (a[i + 1][j] == '#' && a[i][j + 1] == '#') {
				cout << "Impossible";
				return 0;
			}
		}
	}
	if (a[n][m] != '#') cout << "Impossible";
	else cout << "Possible";
	return 0;
}