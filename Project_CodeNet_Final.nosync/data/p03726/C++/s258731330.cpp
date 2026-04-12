#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int n;
vector<int> graph[N];
int leaf[N];

int dfs(int v = 0, int f = 0) {
	int lcnt = 0;
	for (int to : graph[v]) if (to != f) {
		int res = dfs(to, v);
		if (res == 2) return 2;
		if (res == 1) lcnt++;
	}
	if (lcnt == 0) return 1;
	if (lcnt > 1) return 2;
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i + 1 < n; i++) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		graph[a].eb(b);
		graph[b].eb(a);
	}
	int ans = dfs();
	if (ans) puts("First");
	else puts("Second");
	return 0;
}