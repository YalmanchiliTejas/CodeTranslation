#include "bits/stdc++.h"
using namespace std;
#define Would
#define you
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const double pi = acos(-1);
const int SIZE = 1 << 17;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, alp[30];
long long fac[100005], finv[100005], inv[100005];
vector<long long>dij;
struct edge { long long to, cost; };
vector<vector<edge>>G;

bool g[10][10], used[10];;
int dfs(int a, int b, bool visited[10]) {
	bool mon = 1;
	for (int i = 0; i < b; ++i) {
		if (!visited[i]) { mon = 0; }
	}
	if (mon) { return 1; }
	int res = 0;
	for (int i = 0; i < b; ++i) {
		if (!g[a][i] || visited[i]) { continue; }
		visited[i] = 1;
		res += dfs(i, b, visited);
		visited[i] = 0;
	}
	return res;
}

int main() {
	int a, b, c, d;
	cin >> a >> b;
	for (int i = 0; i < b; ++i) {
		cin >> c >> d;
		--c; --d;
		g[c][d] = g[d][c] = 1;
	}
	used[0] = 1;
	cout << dfs(0, a, used) << endl;

}