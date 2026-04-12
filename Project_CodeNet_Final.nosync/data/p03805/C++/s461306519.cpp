#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const int INF = (1 << 30) - 1;
const ll INF64 = ((ll)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int solve(int cur, const vector<vector<int>>& g, const vector<bool>& vec) {
	vector<bool> visited = vec;
	bool complete = [=]() -> bool {
		for (auto x : visited) {
			if (!x) {
				return false;
			}
		}
		return true;
	}();

	if (complete) {
		return 1;
	}

	int res = 0;
	for (auto next : g[cur]) {
		if (visited[next]) {
			continue;
		}

		visited[next] = true;
		res += solve(next, g, visited);
		visited[next] = false;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<bool> visited(n);
	visited[0] = true;

	cout << solve(0, g, visited) << endl;
	return 0;
}
