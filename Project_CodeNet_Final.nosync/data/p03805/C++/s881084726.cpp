#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
bool vis[10];
vector<vector<int>> eg(10);
int ans;

void dfs(int v){
	vis[v] = true;

	bool ok = false;
	for(auto x : eg[v]){
		if(!vis[x]){
			ok = true;
			dfs(x);
		}
	}

	if(!ok){
		ok = true;
		for(int i=1; i<=n; i++)
			if(!vis[i]){
				ok = false;
				break;
			}
		if(ok)
			ans++;
	}

	vis[v] = false;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0, x, y; i<m; i++){
		cin >> x >> y;
		eg[x].push_back(y);
		eg[y].push_back(x);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
