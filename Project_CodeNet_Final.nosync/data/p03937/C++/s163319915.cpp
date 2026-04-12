#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n, m;
char c[N][N];

void NO() {
	cout << "Impossible";
	exit(0);
}

void YES() {
	cout << "Possible";
	exit(0);
}

void go(int x, int y) {
	if (x == (n - 1) && y == (m - 1))
		YES();
	if (x >= n || y >= m)
		return;
	if (c[x + 1][y] == '#')
		go(x + 1, y);
	else if (c[x][y + 1] == '#')
		go(x, y + 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			cnt += (c[i][j] == '#');
		}
	if (c[0][0] != '#' || c[n - 1][m - 1] != '#' || cnt != (n + m - 1))
		NO();
	go(0, 0);
	NO();
}
