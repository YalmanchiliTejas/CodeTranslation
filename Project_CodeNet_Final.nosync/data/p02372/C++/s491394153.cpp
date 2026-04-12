#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

vector<P> G[10000];
int used[10000];
int res1[10000];
int res2[10000];

P dfs(int n) {
	used[n] = 1;
	P res(n, 0);
	for (auto e : G[n]) {
		if (used[e.first] == 0) {
			auto p = dfs(e.first);
			if (p.second + e.second > res.second) {
				res = p;
				res.second += e.second;
			}
		}
	}
	used[n] = 0;
	return res;
}

void dfs1(int n, int d) {
	used[n] = 1;
	res1[n] = d;
	for (auto e : G[n]) {
		if (used[e.first] == 0) {
			dfs1(e.first, d + e.second);
		}
	}
	used[n] = 0;
}

void dfs2(int n, int d) {
	used[n] = 1;
	res2[n] = d;
	for (auto e : G[n]) {
		if (used[e.first] == 0) {
			dfs2(e.first, d + e.second);
		}
	}
	used[n] = 0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0, s, t, w; i < n - 1; i++) {
		cin >> s >> t >> w;
		G[s].push_back(P(t, w));
		G[t].push_back(P(s, w));
	}
	auto s = dfs(0);
	auto t = dfs(s.first);
	dfs1(s.first, 0);
	dfs2(t.first, 0);
	for (int i = 0; i < n; i++) {
		cout << max(res1[i], res2[i]) << endl;
	}
	return 0;
}