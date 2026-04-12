#include<iostream>
#include<vector>
#include<algorithm>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
vector<vector<int>> path;
vector<bool> isvisited;

int dfs(int v, int p = -1) {
	bool visitall = true;
	for (bool u : isvisited) {
		if (!u)visitall = false;
	}
	if (visitall) {
		return 1;
	}
	int ret = 0;
	for(int u : path[v]) {
		if (u == p)continue;
		if (isvisited[u])continue;
		isvisited[u] = true;
		ret += dfs(u, v);
		isvisited[u] = false;
	}
	return ret;
}
int main() {
	int n,m;
	cin >> n >> m;
	path.resize(n);
	isvisited.resize(n);
	rep(i, n) {
		isvisited[i] = false;
	}
	int a, b;
	rep(i, m) {
		cin >> a >> b;
		--a; --b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	isvisited[0] = true;
	cout << dfs(0) << endl;
	return 0;
}