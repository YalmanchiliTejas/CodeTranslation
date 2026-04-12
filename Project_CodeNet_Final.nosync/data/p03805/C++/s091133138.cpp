#include<bits/stdc++.h>
using namespace std;
bool vis[123];
int ans=0;
vector<int>ed[120];
int n,m;
void dfs(int a) {
	vis[a]=1;
	for(int i=0;i<ed[a].size();++i) {
		int tar=ed[a][i];
		if(vis[tar]==0)
			dfs(tar);
	}
	
	int mark=1;
	for(int i=1;i<=n;++i) {
		if(vis[i]==0)
			mark=0;
	}
	if(mark==1)
		ans++;
	vis[a]=0;
	return;
}
int main() {
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;++i) {
		cin>>a>>b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(1);
	cout<<ans;
	return 0;
}