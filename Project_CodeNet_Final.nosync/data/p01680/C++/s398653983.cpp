#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1000000007;

int n,m;
vector<int> G[100010];
bool used[100010];

void dfs(int v){
	used[v] = true;
	for(int to : G[v]){
		if(!used[to]) dfs(to);
	}
}

void solve(){
	for(int i = 0;i < n;i++){
		G[i].clear();
		used[i] = false;
	}
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b; a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int k = 0;
	for(int i = 0;i < n;i++){
		if(!used[i]){
			k++;
			dfs(i);
		}
	}
	int ans = 1;
	for(int i = 0;i < k;i++) ans = ans * 2 % MOD;
	cout << (ans + !!m) % MOD << endl;
}

signed main(){
	while(cin >> n >> m,n) solve();
}
