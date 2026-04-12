#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int n,m,ar[N],sum,q;
char s[10][10];
int dfs(int i,int j)
{
	//~ printf("%d %d\n",i,j);
	if(s[i][j]=='.')
		return 0;	
	if(s[i][j+1]=='#')
		return dfs(i,j+1)+1;
	if(s[i+1][j]=='#')
		return dfs(i+1,j)+1;
	return 0;	
}
int main()
{
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf(" %s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#')
				q++;
	sum=dfs(1,1);
	//~ printf("%d %d\n",sum,q);
	if(s[1][1]=='.')
	{
		printf("Impossible");
		return 0;	
	}
	sum++;
	if(sum==q)
		printf("Possible");
	else
		printf("Impossible");
}
