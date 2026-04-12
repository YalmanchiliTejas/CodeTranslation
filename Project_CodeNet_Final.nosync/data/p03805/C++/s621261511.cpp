#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> graph;
vector<bool> seen;
int cnt = 0;
void dfs(int v)
{
	if (seen[v]) return;
	seen[v] = 1;
	for (int nv : graph[v]) {
		if (seen[nv]) continue;
		dfs(nv);
	}
	bool flag = 1;
	for (int i = 0; i < N; ++i) {
		flag &= seen[i];
	}
	if (flag) {
		++cnt;
	}
	seen[v] = 0;

}
int main()
{
	cin >> N >> M;
	graph.resize(N);
	seen.resize(N, 0);
	for (int i = 0; i < M; ++i) {
		int from, to; cin >> from >> to; --from; --to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	dfs(0);
	cout << cnt << endl;
}
