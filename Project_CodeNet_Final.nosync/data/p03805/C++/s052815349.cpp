#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<numeric>

//完コピ。DFS要勉強

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
	LL r;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
LL lcm(LL a, LL b) {
	return (a / gcd(a, b) * b);
}


bool graph[8][8];

int dfs(int v, int n, bool visited[8]) {
	bool all_visited = true;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}
	if (all_visited) {
		return 1;
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (graph[v][i] == false)
		{
			continue;
		}
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}
	return ret;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}
	bool visited[8];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << dfs(0, n, visited) << endl;
	return 0;
}