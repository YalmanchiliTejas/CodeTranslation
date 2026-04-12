#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#define N 110000
using namespace std;
struct node{int y,nex;}a[2*N];
int n,fir[N],len;
bool bo;
void ins(int x,int y)
{
	a[++len].y=y;a[len].nex=fir[x];fir[x]=len;
}
bool dfs(int x,int fa)
{
	int cnt=0;
	for(int k=fir[x];k;k=a[k].nex)
	{
		int y=a[k].y;
		if(y==fa) continue;
		if(dfs(y,x)==0) cnt++;
		if(bo==0) return 0;
	}
	if(cnt>1) {bo=0;return 0;}
	return cnt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	bo=1;
	if(dfs(1,0)==0 || bo==0) printf("First\n");
	else printf("Second\n");
	return 0;
}