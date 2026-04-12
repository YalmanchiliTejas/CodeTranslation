#include <cstdio>
#include <vector>
using namespace std;

#define iter(i, n) for (int i = 1; i <= n; ++i)
#define NR 101000

int n;
vector<int> g[NR];
bool ans = true;

bool dfs(int x, int fa) {
	bool need = true;
	for (int v : g[x]) if (v != fa) {
		if (dfs(v, x)) {
			if (need) need = false;
			else ans = false;
		}
	}
	return need;
}

int main() {
	scanf("%d", &n);
	iter(i, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	printf("%s\n", (dfs(1, 0) || !ans) ? "First" : "Second");
	return 0;
}