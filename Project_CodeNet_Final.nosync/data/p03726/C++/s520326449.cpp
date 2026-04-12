#include<bits/stdc++.h>
#define pb push_back 
using namespace std;

const int maxn=1e5+7;
typedef long long ll;

int n,m,ans;
int a[maxn];
vector<int>e[maxn];
int flag;

void dfs(int x,int pre)
{
	a[x]=1;
	int len=e[x].size();
	int f=0;
	for(int i=0;i<len;++i)
	{
		int v=e[x][i];
		if(v!=pre)
		{
			dfs(v,x);
			if(flag) f++,flag=0;
			a[x]+=a[v];
		}
		
	}
	if(f>1)
	{
		printf("First");
		exit(0);
	}
	
	
	if(a[x]%2)
	{
		flag=1;
	}
}

int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].pb(y);
		e[y].pb(x);
	}
	if(n%2)
	{
		printf("First");
		return 0;
	}
	
	dfs(1,0);
	
	printf("Second");
	
	return 0;
}
