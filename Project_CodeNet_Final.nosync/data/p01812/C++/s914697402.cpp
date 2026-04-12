#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> G(N, vector<int>(K));
	vector<int> is(N);
	vector<int> D(M);
	for (int i = 0; i < M; i++) {
		cin >> D[i]; D[i]--;
		is[D[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> G[i][j]; G[i][j]--;
		}
	}
	vector<int> res(1 << M, 10000);
	int s = (1 << M) - 1; res[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		for (int i = 0; i < K; i++) {
			int t = 0;
			for (int j = 0; j < M; j++) {
				if (p & (1 << j)) {
					if (is[G[D[j]][i]]) {
						int id = 0;
						for (int k = 0; k < M; k++) {
							if (D[k] == G[D[j]][i]) {
								id = k;
								break;
							}
						}
						t |= 1 << id;
					}
				}
			}
			if (res[t] == 10000) {
				res[t] = res[p] + 1;
				q.push(t);
			}
		}
	}
	cout << res[0] << endl;
	return 0;
}