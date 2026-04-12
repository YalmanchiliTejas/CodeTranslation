#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(), (v).end()

int N, M;
bool graph[8][8];
int ans = 0;

void dfs(int v, int visited) {
		visited |= (1<<v);
		if(__builtin_popcount(visited) == N) {
				ans++;
				return;
		}

		for (int v2 = 0; v2 < N; v2++) {
				if (!graph[v][v2]) continue;
				if (visited & (1<<v2)) continue;
				dfs(v2, visited);
		}
}

int main() {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
				int a, b;
				cin >> a >> b;
				a--; b--;
				graph[a][b] = graph[b][a] = true;
		}

		dfs(0, 0);
		cout << ans << endl;
		return 0;
}
