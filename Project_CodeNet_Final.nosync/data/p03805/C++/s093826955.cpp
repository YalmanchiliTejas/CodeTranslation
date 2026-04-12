#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, ans;
vector<int> G[8];

void dfs(int v, int p, int b) {
	if(b == (1 << N) - 1) {
		ans++;
		return;
	}
	for(auto c : G[v]) {
		if(~b >> c & 1) {
			dfs(c, v, b ^ (1 << c));
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(0, -1, 1);
	cout << ans << endl;
}