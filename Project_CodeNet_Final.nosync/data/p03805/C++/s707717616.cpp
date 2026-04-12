#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;

const int nmax = 8;
bool graph[nmax][nmax];

Int dfs(Int v, Int N, bool visited[nmax]) {

	bool all_visited = true;
	for (Int i = 0; i < N; i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}
	if (all_visited) {
		return 1;
	}

	Int ret = 0;

	for (Int i = 0; i < N; i++) {
		if (graph[v][i] == false)continue;
		if (visited[i])continue;

		visited[i] = true;
		ret += dfs(i, N, visited);
		visited[i] = false;
	}
	return ret;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int N, M;
	cin >> N >> M;

	for (Int i = 0; i < M; i++) {
		Int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}

	bool visited[nmax];
	for (Int i = 0; i < N; i++) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << dfs(0, N, visited) << "\n";


}