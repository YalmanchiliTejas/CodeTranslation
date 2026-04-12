#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt;
int fir[202020],nxt[404040],to[404040],du[202020];
void add(int x,int y)
{
	nxt[++cnt]=fir[x];fir[x]=cnt;
	to[cnt]=y;
}
bool calc(int x,int fa)
{
	int son=0;
	for(int i=fir[x];i;i=nxt[i])
	if(to[i]!=fa)
		son+=calc(to[i],x);
	if(son>1)
	{
		puts("First");
		exit(0);
	}
	return !son;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		du[x]++;du[y]++;
	}
	for(int i=1;i<=n;i++)
	if(du[i]>1)
	{
		if(calc(i,0)) puts("First");
		else puts("Second");
		return 0;
	}
	if(n==1) puts("First");
	else puts("Second");
	return 0;
}