#include <bits/stdc++.h>
using namespace std;

const int N = 8 + 7;

int n, m;
char c[N][N];
bool mrk[N][N];

void dfs(int x, int y) {
	mrk[x][y] = 1;
	if (x < n && c[x + 1][y] == '#' && !mrk[x + 1][y])
		dfs(x + 1, y);
	if (y < m && c[x][y + 1] == '#' && !mrk[x][y + 1])
		dfs(x, y + 1);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	dfs(1, 1);

	for (int i = 1; i <= n; i++)
   		for (int j = 1; j <= m; j++)
			if (c[i][j] == '#' && !mrk[i][j]) {
				cout << "Impossible";
				return 0;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[i][j] == '#') 
				for (int x = 1; x <= n; x++)
					for (int y = 1; y <= m; y++)
						if (c[x][y] == '#')
							if ((i > x && j < y) || (i < x && j > y)) {
								cout << "Impossible";
								return 0;
							}
	cout << "Possible";
	return 0;
}
