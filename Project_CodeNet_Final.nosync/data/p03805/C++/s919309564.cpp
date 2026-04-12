#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct Edge {
	int s;
	int t;
	Edge(int s, int t) :s(s), t(t) {}
};

ll N, M;
ll ans = 0;

void dfs(ll n,ll x, vector<vector<Edge>> &G, vector<bool> used) {
	if (x == N - 1) { ans++; return; }
	used[n] = true;
	for (auto e : G[n]) {
		int next = e.t;
		if (!used[next]) {
			dfs(next, x + 1, G, used);
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N >> M;
	vector<vector<Edge>> G(N);
	for (int i = 0; i < M;i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(Edge(a, b));
		G[b].push_back(Edge(b, a));
	}
	vector<bool> used(N, false);
	dfs(0,0,G, used);
	cout << ans << endl;
}