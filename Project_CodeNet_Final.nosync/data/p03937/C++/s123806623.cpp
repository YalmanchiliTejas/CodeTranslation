#include <bits/stdc++.h>
using namespace std;
#define int long long
#define END getchar();getchar();return 0
#define inf 1000000007

int h, w, cnt;
char a[10][10];

void dfs(int i, int j) {
	if (i == 0 || j == 0 || i > h || j > w || a[i][j] != '#') {
		return;
	}
	cnt--;
	a[i][j] = '.';
	dfs(i + 1, j);
	dfs(i, j + 1);
	return;
}

signed main() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				cnt++;
			}
		}
	}
	int x = 1, y = 1;
	while (1) {
		cnt--;
		if (a[x + 1][y] == '#'&&a[x][y + 1] == '#') break;
		else if (a[x + 1][y] == '#') {
			x++;
			continue;
		}
		else if (a[x][y + 1] == '#') {
			y++;
			continue;
		}
		else break;
	}
	if (!cnt) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

	END; 
}
