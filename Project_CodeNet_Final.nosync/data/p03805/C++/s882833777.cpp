#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 8, MAX_M = MAX_N * (MAX_N - 1) / 2;

int N, M, a[MAX_M], b[MAX_M];

vector<int> graph[MAX_N];
bool used[MAX_N];

int dfs(int n) {
	used[n] = true;
	
	bool end = true;
	for (int i = 0; i < N; i++) {
		end &= used[i];
	}
	if (end) {
		used[n] = false;
		return 1;
	}

	int res = 0;
	for (int i = 0; i < graph[n].size(); i++) {
		if (!used[graph[n][i]]) {
			res += dfs(graph[n][i]);
		}
	}
	
	used[n] = false;
	return res;
}

void solve() {
	for (int i = 0; i < M; i++) {
		graph[a[i] - 1].push_back(b[i] - 1);
		graph[b[i] - 1].push_back(a[i] - 1);
	}

	memset(used, false, sizeof(used));

	int res = dfs(0);
	printf("%d\n", res);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}

	solve();
}