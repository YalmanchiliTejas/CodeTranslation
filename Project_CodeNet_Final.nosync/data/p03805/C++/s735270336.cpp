#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<cstring>
#include<utility>
#include<vector>
#include<memory>
using namespace std;

int n,m;
int ans=0;
vector<int> gra[11];
bool used[11];

void dfs(int x,int s)
{
	if(s==n)
	{
		ans++;
		return;
	}
	for(int i=0;i<gra[x].size();i++)
	{
		if(used[gra[x][i]]==false)
		{
			used[gra[x][i]]=true;
			dfs(gra[x][i],s+1);
			used[gra[x][i]]=false;
		}
	}
}

int main()
{
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		gra[a].push_back(b);
		gra[b].push_back(a); 
	}
	used[1]=true;
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}