#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> path[10];
int cnt=0;
int n,m;

inline void dfs(vector<int> went,int now)
{
	if((int)went.size()==n)
	{
		cnt++;
		return;
	}
	for(int i=0;i<path[now].size();i++)
	{
		bool lgl=false;
		for(int j=0;j<went.size();j++)
			if(path[now][i]==went[j])lgl=true;
		if(!lgl)
		{
			went.push_back(path[now][i]);
			dfs(went,path[now][i]);
			went.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		path[a].push_back(b);
		path[b].push_back(a);
	}
//	for(int i=1;i<=n;i++)
//		for(int j=0;j<path[i].size();j++)cout<<path[i][j]<<' ';
	vector<int> linsh;linsh.push_back(1);
	dfs(linsh,1);
	printf("%d\n",cnt);
	return 0;
}