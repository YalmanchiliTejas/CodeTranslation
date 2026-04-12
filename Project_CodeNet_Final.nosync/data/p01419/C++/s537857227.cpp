#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=51;
const int xx[4]={1,-1,0,0};
const int yy[4]={0,0,1,-1};
int endx,endy;
int n,m;
int num[maxn][maxn];
int q[maxn][maxn][1001];
bool visit[maxn][maxn];
char s[maxn][maxn];
int now;

bool ins(int x,int y)
{
	return x>=0&&x<n&&y>=0&&y<m;
}

bool dfs(int x,int y,int dep)
{
	visit[x][y]=1;
	if (x==endx&&y==endy)
	{
		 q[x][y][ num[x][y]++]=dep;
		 now=dep;
		 return 1;
	}
	for(int i=0;i<4;i++)
	{
		int nowx=x+xx[i];
		int nowy=y+yy[i];
		if (ins(nowx,nowy)&&!visit[nowx][nowy]&&s[nowx][nowy]=='.')
		{
			if (dfs(nowx,nowy,dep+1))
			{
				q[x][y][ num[x][y]++]=dep;
				return 1;
			}
		}
	}
	return 0;
}

int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];

int main()
{
	int k;
	while(scanf("%d %d %d",&n,&m,&k)==3)
	{
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++) scanf("%d",&b[i][j]);
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++) scanf("%d",&c[i][j]);
		memset(num,0,sizeof(num));
		int xx,yy;
		scanf("%d %d",&xx,&yy);
		bool first=1;

		now=0;
		k--;
		while(k--)
		{
			scanf("%d %d",&endx,&endy);
			memset(visit,0,sizeof(visit));
			dfs(xx,yy,now);
			if (!first) num[xx][yy]--;
			first=0;
			xx=endx;yy=endy;
		}
		int ans=0;
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++)
		  if (num[i][j])
		  {
		  	ans+=b[i][j]+c[i][j];
		  	for(int k=0;k<num[i][j]-1;k++)
		  	{
		  		int t=min(b[i][j]+c[i][j],
						 (q[i][j][k+1]-q[i][j][k])*a[i][j]);
		  		ans+=t;
		  	}
		  }
		printf("%d\n",ans);
	}
	return 0;
}