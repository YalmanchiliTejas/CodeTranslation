#include "bits/stdc++.h"

using namespace std;
static const int INF = (1 << 21);

int E[8][8 ] = { { 0 } };
int N, M;
int c = 0;
int flag[8] = { 0 };

void dfs(int u) {
	int sum = 0;
	for (int i = 0;i < N;i++) {
		sum += flag[i];
	}
	if (sum == N) {
		c++;
	}
	else {
		for (int v = 0;v < N;v++) {
			if (E[u][v] == 1&&flag[v]==0) {
				flag[v] = 1;
				E[v][u] = E[u][v] = 0;
				dfs(v);
				E[v][u] = E[u][v] = 1;
				flag[v] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		E[u][v] = E[v][u] = 1;
	}
	flag[0] = 1;
	dfs(0);
	cout << c << endl;
}