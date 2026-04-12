#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 8;
vector<int> G[MAX_N];
bool used[MAX_N];
int N, M;
int res;
void dfs(int u, int depth){
	if (depth == N - 1){
		++res;
		return;
	} // end if

	used[u] |= true;
	rep (i, (int)G[u].size()){
		int v = G[u][i];
		if (!used[v]){
			dfs(v, depth + 1);
		} // end if
	} // end rep
	used[u] = false;
}

int main()
{
	memset(used, false, sizeof(used));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	rep (i, MAX_N) G[i].clear();

	cin >> N >> M;
	rep (i, M){
		int a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	} // end rep
	res = 0;
	dfs(0, 0);
	cout << res << endl;
	
	return 0;
}