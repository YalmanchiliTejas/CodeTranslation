#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char a[10][10];
int n,m,cnt1,cnt2;
void dfs(int x,int y)
{
	int f=0;
	cnt2++;
	if(x==n&&y==m)
		return ;
	int dx=x,dy=y+1;
	if(dx>=0&&dx<n&&dy>=0&&dy<m)
		if(a[dx][dy]=='#')
		{
			dfs(dx,dy);
			f=1;
		}
	if(!f)
	{
		dx=x+1,dy=y;
		if(dx>=0&&dx<n&&dy>=0&&dy<m)
			if(a[dx][dy]=='#')
				dfs(dx,dy);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]=='#')
				cnt1++;
	dfs(0,0);
	if(cnt1-cnt2!=0)
		printf("Impossible\n");
	else
		printf("Possible\n");
	return 0;
}
