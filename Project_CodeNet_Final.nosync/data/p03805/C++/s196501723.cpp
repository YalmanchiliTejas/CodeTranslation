#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = INT_MAX;
constexpr ll L_INF = LLONG_MAX;

//===

using Graph = std::vector<std::vector<int>>;

int N, M;
Graph g;
ll ans = 0;

void dfs(int n, int a, vector<bool> chkd)
{
	if (n == N - 1) {
		++ans;
	}

	chkd[a] = true;

	for (const auto& to : g[a]) {
		if (chkd[to]) continue;
		dfs(n + 1, to, chkd);
	}
}



int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	g.resize(N);


	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0, 0, vector<bool>(N));

	cout << ans << "\n";

	return 0;
}