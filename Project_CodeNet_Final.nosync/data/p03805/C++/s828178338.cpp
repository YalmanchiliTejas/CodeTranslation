#include<bits/stdc++.h>
using namespace std;
int n,m;
std::vector<vector<bool>> edge;
std::vector<bool> used;
int dfs(int now,int depth){
	if(used[now]) return 0;
	if(depth==n) return 1;
	int ans=0;
	used[now]=true;
	for (int i = 0; i < n; ++i)
	{
		if(edge[now][i]){
			ans+=dfs(i,depth+1);
		}
	}
	used[now]=false;
	return ans;
}

int main()
{
	cin>>n>>m;
	used=std::vector<bool>(n,false);
	edge.resize(n);
	for (int i = 0; i < n; ++i)
	{
		edge[i].resize(n);
	}
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		edge[a][b]=edge[b][a]=true;
	}
	cout<<dfs(0,1);
}