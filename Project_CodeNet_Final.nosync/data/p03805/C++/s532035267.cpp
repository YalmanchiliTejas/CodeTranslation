#include <bits/stdc++.h>
using namespace std;

int N, M;
int v[8][8];
int used[8];

bool check() {
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			return false;
		}
	}
	return true;
}

int dfs(int now) {
	used[now] = 1;

	if (check()) {
		used[now] = 0;
		return 1;
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (!used[i] && v[now][i]) {
			res += dfs(i);
		}
	}
	used[now] = 0;

	return res;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--;
	   	y--;
		v[x][y] = v[y][x] = 1;
	}

	cout << dfs(0) << endl;

	return 0;
}
