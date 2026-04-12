#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

const int N = 11;

int n, m;
char s[N][N];

bool solve() {
	if (s[0][0] != '#') return false;
	int cnt = 1;	
	int x, y;
	x = 0, y = 0;
	while (x + 1 < n || y + 1 < m) {
		if (x + 1 < n && s[x + 1][y] == '#') {
			x++;
		} else if (y + 1 < m && s[x][y + 1] == '#') {
			y++;
		} else {
			return false;
		}
		cnt++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') cnt--;
		}
	}
	return cnt == 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	printf("%s\n", solve() ? "Possible" : "Impossible");
	return 0;
}