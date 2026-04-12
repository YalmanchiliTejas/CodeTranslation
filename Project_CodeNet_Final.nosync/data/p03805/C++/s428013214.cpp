#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	bool g[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			g[i][j] = false;
		}
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = true;
	}

	int ans = 0;
	int j = 1;
	vector<int> v;
	for (int i = 2; i <= N; i++) {
		v.push_back(i);
	}

	do {
		j = 1;
		int i;
		for (i = 0; i < N - 1; i++) {
			if (!g[j][v[i]]) {
				break;
			}
			j = v[i];
		}
		if (i == N - 1) {
			ans++;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << endl;

	return 0;
}