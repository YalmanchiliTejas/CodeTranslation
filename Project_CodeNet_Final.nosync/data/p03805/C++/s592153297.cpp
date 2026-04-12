#include<bits/stdc++.h>

using namespace std;

int n,m,tal = 1,ans;
int edges[10][10], vis[10];

void dfs(int src){
	if(tal==n){
		tal--;
		ans++;
		return;
	}
	vis[src] = 1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0 && edges[src][i]){
			vis[i] = 1;
			tal++;
			dfs(i);
			vis[i] = 0; //back-track
		}
	}
	tal--;
	vis[src] = 0; //back-track
}

int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}
	dfs(1);
	cout << ans << "\n";
	
	return 0;
}