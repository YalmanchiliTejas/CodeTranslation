#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int N, M; 		// グラフの頂点数、辺の数
vector<int> G[8]; 	// 隣接グラフ表現
bool visit[8];

int res;		// ハミルトンパスの数

void dfs(int u, int p, int depth){
	if (depth == N - 1){
		++res;
		return;
	} // end if

	visit[u] |= true;
	rep (i, (int)G[u].size()){
		int v = G[u][i];
		if (v != p && !visit[v]){
			dfs(v, u, depth + 1);
		} // end if
	} // end rep
	visit[u] = false;
}

int main()
{
	rep (i, 8){
		G[i].clear();
		visit[i] = false;
	} // end rep

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	rep (i, M){
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	} // end rep

	res = 0;
	dfs(0, -1, 0);

	cout << res << endl;

	return 0;
}