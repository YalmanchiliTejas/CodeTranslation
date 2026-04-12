#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> e;
int N, M;

int path(int pos, vector<bool> memo) {
	memo[pos] = true;

	bool check = true;
	for (int i = 0; i < N; i++) {
		if (!memo[i]) check = false;
	}
	if (check) return 1; 

	int ret = 0;
	for (int i = 0; i < e[pos].size(); i++) {
		if (!memo[e[pos][i]]) {
			ret += path(e[pos][i], memo);
		}
	}
	return ret;
}

int main() {
	cin >> N >> M;
	e.resize(N);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;  b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	vector<bool> memo(N);
	fill(memo.begin(), memo.end(), false);
	memo[0] = true;
	cout << path(0, memo) << endl;
}
