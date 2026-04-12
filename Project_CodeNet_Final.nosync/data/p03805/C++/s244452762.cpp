#include "bits/stdc++.h"
using namespace std;
bool G[8][8];
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		v.push_back(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			G[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a][b] = G[b][a] = 1;
	}
	int cnt = 0;
	do {
		if (v[0] != 0) continue;
		bool OK = 1;
		for (int i = 1; i < N; i++) {
			if (!G[v[i - 1]][v[i]]) {
				OK = 0;
				break;
			}
		}
		if (OK) cnt++;
	} while (next_permutation(v.begin(), v.end()));
	cout << cnt << endl;
}