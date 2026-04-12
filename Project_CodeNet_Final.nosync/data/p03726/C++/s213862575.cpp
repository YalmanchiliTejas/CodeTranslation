#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, dp[2][maxn], pre[maxn], suf[maxn];
vector<int> adj[maxn], adj2[maxn];

void prep(int v, int p){
	for(int u : adj2[v]){
		if(u != p){
			prep(u, v);
			adj[v].push_back(u);
		}
	}
}

void dfs(int v){
	if(adj[v].size() == 0){
		dp[1][v] = true;
		dp[0][v] = false;
		return;
	}

	dfs(adj[v][0]);
	dp[1][v] = dp[0][adj[v][0]];
    for(int i = 1; i < adj[v].size(); i++){
		int u = adj[v][i];

		dfs(u);

		dp[1][v] &= dp[0][u];
    }

	pre[0] = dp[0][adj[v][0]];
    for(int i = 1; i < adj[v].size(); i++){
		int u = adj[v][i];

		pre[i] = dp[0][u] & pre[i - 1];
    }

    suf[adj[v].size()] = 1;
    for(int i = adj[v].size() - 1; i >= 0; i--){
		int u = adj[v][i];

		suf[i] = dp[0][u] & suf[i + 1];
    }

    dp[0][v] = dp[1][adj[v][0]] & suf[1];

    for(int i = 1; i < adj[v].size(); i++){
		dp[0][v] |= (pre[i - 1] & dp[1][adj[v][i]] & suf[i + 1]);
    }
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		adj2[a].push_back(b);
		adj2[b].push_back(a);
	}

	prep(1, 0);
	dfs(1);

	cout << (dp[0][1] ? "Second" : "First") << endl;

//	for(int i = 1; i <= n; i++){
//		cout << i << ' ' << dp[0][i] << ' ' << dp[1][i] << endl;
//	}
//
//	for(int i = 0; i <= 2; i++){
//		cout << pre[i];
//	}

	return 0;
}
