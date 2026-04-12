#include <bits/stdc++.h>

using namespace std;

char a[11][11];

void no () {
	cout << "Impossible";
	exit (0);
}

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= m;j ++) {
			cin >> a[i][j];
		}
	}   
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= m;j ++) {
			if (a[i][j] == '.') continue;
			int kol = 0, kol1 = 0;
			if (a[i - 1][j] == '#') kol1 ++;
			if (a[i + 1][j] == '#') kol ++;
			if (a[i][j - 1] == '#') kol1 ++;
			if (a[i][j + 1] == '#') kol ++;
			if (kol + kol1 > 2) no ();
			if (kol1 > 1) no ();
			if (kol > 1) no ();
		}
	}
	cout << "Possible";
	return 0;
}