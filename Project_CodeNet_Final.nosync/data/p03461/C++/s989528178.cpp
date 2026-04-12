#include<cstdio>
#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksub
#define y1 fuckjtjl
struct edges
{
	int x,y,z;
};
int d[15][15];
bool vis[20][20];
int tot,n,idx[120],idy[120],S,T,A,B;
vector<edges> edge;
void check()
{
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			if(!vis[i][j])
			{
			puts("Impossible");
			exit(0);
		}
		}
	}
}
int get(int p,int q)
{
	int c=-1000000;
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			c=max(c,d[i][j]-i*p-j*q);
		}
	}
	if(c<0)
	{
		return -3;
	}
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			if(d[i][j]-i*p-j*q==c)
			{
				vis[i][j]=1;
			}
		}
	}
	return c;
}
void add(int x,int y,int z)
{
	if(z==-3)
	{
		return;
	}
	edge.push_back({x,y,z});
}
int main()
{
	scanf("%d%d",&A,&B);
	for(int i=1;i<=A;i++)
	{
		for(int j=1;j<=B;j++)
		{
			scanf("%d",&d[i][j]);
		}
	}
	S=1;T=2;tot=2;
	idx[0]=S;idy[0]=T;
	for(int i=1;i<=100;i++)
	{
		idx[i]=++tot;
		idy[i]=++tot;
	}
	for(int i=1;i<=100;i++)
	{
		add(idx[i-1],idx[i],-1);
		add(idy[i],idy[i-1],-2);
	}
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			add(idx[i],idy[j],get(i,j));
		}
	}
	check();
	puts("Possible");
	int cnt=edge.size();
	printf("%d %d\n",tot,cnt);
	for(int i=0;i<cnt;i++)
	{
		printf("%d %d ",edge[i].x,edge[i].y);
		if(edge[i].z>=0)
		{
			printf("%d\n",edge[i].z);
		}
		else if(edge[i].z==-1)
		{
			puts("X");
		}
		else
		{
			puts("Y");
		}
	}
	printf("%d %d\n",S,T);
	return 0;
}