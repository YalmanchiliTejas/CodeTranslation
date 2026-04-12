#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N, vector<int>(N));
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a][b] = G[b][a] = 1;
	}

	vector<int> P(N);
	for(int i = 0; i < N; i++) P[i] = i;

	int ans = 0;
	do {
		int now = P[0];
		if (now != 0) continue;
		int flag = 1;
		for(int i = 0; i < N - 1; i++) {
			if (!G[now][P[i + 1]]) {
				flag = 0;
				break;
			}
			now = P[i + 1];
		}
		ans += flag;
	} while(next_permutation(P.begin(), P.end()));
	cout << ans << endl;
}
