#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<cmath>
#include<queue>
#include<limits>
#include<cassert>
#include<set>
#include<tuple>
#include<map>
#include<list>

#define PB push_back
#define ALL(a)  (a).begin(),(a).end()
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
typedef long long ll;

bool gragh[8][8];

int dfs(int v, int n, bool visited[8]) {
	bool all_visited = true;
	REP(i, n) {
		if (!visited[i]) all_visited = false;
	}
	if (all_visited) return 1;
	int ret = 0;
	REP(i, n) {
		if (!gragh[v][i]) continue;
		if (visited[i]) continue;
		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		gragh[a - 1][b - 1] = gragh[b - 1][a - 1] = true;
	}
	bool visited[8];
	REP(i, n) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;
}