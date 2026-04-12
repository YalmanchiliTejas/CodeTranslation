#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N, vector<int>(N));
	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		G[a - 1][b - 1]++;
		G[b - 1][a - 1]++;
	}
	long long res = 0;
	vector<int> g(N);
	for (int i = 0; i < N; i++) {
		g[i] = i;
	}
	do {
		if (g[0] == 0) {
			bool f = true;
			for (int i = 1; i < N; i++) {
				if (G[g[i - 1]][g[i]] == 0) {
					f = false;
					break;
				}
			}
			if (f) {
				res++;
			}
		}
	} while (next_permutation(g.begin(), g.end()));
	cout << res << endl;
	return 0;
}
