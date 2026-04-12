#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

int dfs(vector<vector<int>>& to, vector<bool> visited, int s = 0) {
	visited[s] = true;
	if (!EXIST(visited, false)) return 1;
	int ret = 0;
	for (auto& v : to[s]) {
		if (visited[v]) continue;
		ret += dfs(to, visited, v);
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> to(n, vector<int>());
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	vector<bool> visited(n, false);
	int ans = dfs(to, visited);
	cout << ans << endl;

	return 0;
}
