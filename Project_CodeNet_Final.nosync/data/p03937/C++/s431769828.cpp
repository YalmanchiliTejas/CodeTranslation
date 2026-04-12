#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int N=19;
int h,w;
char g[N][N];
bool vis[N][N];

inline void end()
{
	puts("Impossible");
	exit(0);
}

int main()
{
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)
		scanf("%s",g[i]+1);
	int x=1,y=1;
	while(x!=h || y!=w)
	{
		vis[x][y]=1;
		if(h==x)
		{
			if(g[x][y+1]!='#')end();
			else y++;
		}
		else if(w==y)
		{
			if(g[x+1][y]!='#')end();
			else x++;
		}
		else
		{
			if((g[x+1][y]=='#')^(g[x][y+1]=='#'))
			{
				if(g[x+1][y]=='#')x++;
				else y++;
			}
			else end();
		}
	}
	vis[h][w]=1;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(!vis[i][j] && g[i][j]=='#')
				end();
	puts("Possible");
	return 0;
}
