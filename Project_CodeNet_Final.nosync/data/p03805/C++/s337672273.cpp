#include<bits/stdc++.h>
using namespace std;
int n,m;
std::vector<vector<bool>> edge;
std::vector<bool> flag;

int dfs(int node=0,int num=1){
	if(flag[node]) return 0;
	if(num==n){
		return 1;
	}
	int ans=0; flag[node]=true;
	for(int i=0;i<n;i++) {
		if(edge[node][i]){
			ans+=dfs(i,num+1);
		}
	}
	flag[node]=false;
	return ans;
}

int main()
{
	cin>>n>>m;
	flag=vector<bool>(n,false);
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
	cout<<dfs();
}