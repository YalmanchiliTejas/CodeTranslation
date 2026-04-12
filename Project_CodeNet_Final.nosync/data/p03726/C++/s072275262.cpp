/******************************************
*    AUTHOR:         CHIRAG AGARWAL       *
*    INSTITUITION:   BITS PILANI, PILANI  *
******************************************/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL; 
typedef long double LD;
const int MAX=1e5+5;
vector<int> adj[MAX];


void first()
{
	printf("First\n");
	exit(0);
}

void second()
{
	printf("Second\n");
	exit(0);
}

int dfs(int s,int p)
{
	int val=0;
	for(int i=0;i<adj[s].size();i++)
	{
		int u=adj[s][i];
		if(u!=p)
		{
			val+=dfs(u,s);
		}
	}
	if(val>=2)
	{
		first();
	}
	if(val==0)
	{

		return 1;
	}
	return 0;
}

int main() 
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(dfs(1,0))
	{
		first();
	}
	second();
	return 0;
}