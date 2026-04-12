#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
vector<int> adj[MAXN];

int dfs(int v, int p = -1){
	int cnt = 0;
	for (int u:adj[v])
		if (u^p){
			int x = dfs(u, v);
			if (x)
				cnt++;
		}

	if (!cnt){
		if (~p)
			return 1;
		cout << "First\n";
		exit(0);
	}
	if (cnt == 1) return 0;
	cout << "First\n";
	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	cout << "Second\n";
	return 0;
}
