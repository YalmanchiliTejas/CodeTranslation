#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, col[100005];
vector<int> linker[100005];
void dfs(int x, int fa)
{
	int cnt = 0;
	for (int cur : linker[x])
		if (cur != fa) dfs(cur, x), cnt += col[cur] ^ 1;
	if (cnt > 1) puts("First"), exit(0);
	if (cnt) col[x] = 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	if (n & 1) {return puts("First"), 0;}
	for (int i = 1; i < n; i ++)
	{
		int u, v; cin >> u >> v;
		linker[u].push_back(v);
		linker[v].push_back(u);
	}
	dfs(1, 0);
	puts("Second");
	return 0;
}