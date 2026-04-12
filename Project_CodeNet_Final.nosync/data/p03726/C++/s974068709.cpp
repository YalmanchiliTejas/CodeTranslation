#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 10289;

const int N = 1e5 + 20;
vector<int> G[N];
int n, sz[N];
bool mat = 1;

void dfs(int v, int p = -1) {
	sz[v] = 1;
	for (int u : G[v])
		if (u - p)
			dfs(u, v), sz[v] += sz[u];
	int cnt = 0;
	for (int u : G[v])
		if (u - p)
			cnt += sz[u] % 2;
	cnt += (n - sz[v]) % 2;
	if (cnt != 1)
		mat = 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0, v, u; i < n - 1; i++) {
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	dfs(1);
	cout << (mat ? "Second" : "First") << endl;
}

