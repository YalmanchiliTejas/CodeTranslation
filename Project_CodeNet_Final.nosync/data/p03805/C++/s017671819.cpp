#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Node;
vector<int> vs;
int ans;
int N, M;

void dfs(int v, int cnt, vector<int> vs)
{
	if (vs[v]) return;
	if (cnt == N-1) ans++;
	vs[v] = 1;
	for (auto t : Node[v]) dfs(t, cnt+1, vs);
}

int main()
{
	cin >> N >> M;
	Node.resize(N);
	vs.resize(N, 0);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;	b--;
		Node[a].push_back(b);
		Node[b].push_back(a);
	}
	dfs(0, 0, vs);
	cout << ans << endl;
	return 0;
}
