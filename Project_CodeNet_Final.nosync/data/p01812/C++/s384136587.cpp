#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, x, ql, qr, p[109], g[19][109], v[65555][109], dist[65555], que[6555555];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	fill(p, p + N, -1);
	for (int i = 0; i < M; i++) {
		cin >> x;
		p[--x] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> x;
			if (p[i] != -1) g[p[i]][j] = --x;
		}
	}
	for (int i = 1; i < 1 << M; i++) {
		for (int j = 0; j < M; j++) {
			if (!((i >> j) & 1)) continue;
			for (int k = 0; k < K; k++) {
				if (p[g[j][k]] != -1) v[i][k] |= 1 << p[g[j][k]];
			}
		}
	}
	fill(dist, dist + (1 << M), -1);
	que[qr++] = (1 << M) - 1;
	dist[(1 << M) - 1] = 0;
	while (ql != qr) {
		int u = que[ql]; ql++;
		for (int i = 0; i < K; i++) {
			if (dist[v[u][i]] == -1) {
				dist[v[u][i]] = dist[u] + 1;
				que[qr++] = v[u][i];
			}
		}
	}
	cout << dist[0] << "\n";
	return 0;
}
