#include<iostream>
#include<cstdio>
#include<cstring>
const int N=10;
bool got(){for(char c;;)if((c=getchar())=='.')return 0;else if(c=='#')return 1;}
bool G[N][N];
int cnt[N*2];
int n,m;
int main()
{
//	freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	bool flag=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			G[i][j]=got();
			if((i>1 || j>1) && G[i][j] && !G[i-1][j] && !G[i][j-1])
				flag=0;
			cnt[i+j]+=G[i][j];
		}

	for(int i=2;i<=n+m;i++)
		flag&=(cnt[i]==1);
	printf("%s\n",flag?"Possible":"Impossible");
	return 0;
}
