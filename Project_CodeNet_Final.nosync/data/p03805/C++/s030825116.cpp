#include<bits/stdc++.h>
using namespace std;

int N, M;

vector<int> G[8];
int used[8];

int dfs(int s) {
	used[s] = 1;
	int res = 0;
	for (int v : G[s]) {
		if (!used[v]) {
			res += dfs(v);
		}
	}
	if (res == 0) {
		bool f = true;
		for (int i = 0; i < N; i++) {
			if (!used[i]) {
				f = false;
				break;
			}
		}
		if (f) {
			res = 1;
		}
	}
	used[s] = 0;
	return res;
}

int main()
{
	cin >> N >> M;
	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		G[a - 1].push_back(b - 1);
		G[b - 1].push_back(a - 1);
	}
	cout << dfs(0) << endl;
	return 0;
}
