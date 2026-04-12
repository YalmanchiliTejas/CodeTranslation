#include <queue>
#include <iostream>
using namespace std;
const int inf = 1012345678;
int N, M, K, d[16], v[109][109], dist[65555], f[109];
int main() {
	cin >> N >> M >> K;
	fill(f, f + N, -1);
	for (int i = 0; i < M; i++) cin >> d[i], f[--d[i]] = i;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> v[i][j];
			v[i][j] = f[v[i][j] - 1];
		}
	}
	fill(dist, dist + (1 << M), inf);
	dist[(1 << M) - 1] = 0;
	queue<int> que; que.push((1 << M) - 1);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = 0; i < K; i++) {
			int bit = 0;
			for (int j = 0; j < M; j++) {
				if (u & (1 << j)) {
					if (v[d[j]][i] != -1) bit |= 1 << v[d[j]][i];
				}
			}
			if (dist[bit] == inf) {
				dist[bit] = dist[u] + 1;
				que.push(bit);
			}
		}
	}
	cout << dist[0] << endl;
	return 0;
}