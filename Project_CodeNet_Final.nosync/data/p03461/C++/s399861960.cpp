#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 2005
using namespace std;
int a,b,tot;
int d[maxn][maxn];
int dis[maxn][maxn];
int head[maxn],nex[maxn*maxn],to[maxn*maxn];
string val[maxn*maxn];
void add(int x,int y,string z)
{
	to[++tot]=y; val[tot]=z; nex[tot]=head[x]; head[x]=tot;
}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			scanf("%d",&d[i][j]);

	for(int i=1;i<=100;i++)
		add(i,i+1,"X");

	for(int i=102;i<=201;i++)
		add(i,i+1,"Y");
	
//	cerr<<"+2"<<endl;

	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			int temp=0;
			for(int k=1;k<=a;k++)
			{
				for(int o=1;o<=b;o++)
				{
					temp=max(temp,d[k][o]-k*i-o*j);
				}
			}
//			cerr<<"its "<<i<<" "<<j<<endl;	
			add(i+1,202-j,to_string(temp));

			for(int k=1;k<=a;k++)
			{
				for(int o=1;o<=b;o++)
				{
					dis[k][o]=min(dis[k][o],temp+i*k+o*j);
				}
			}
		}
	}

//	cerr<<"+1"<<endl;

	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		if(dis[i][j]!=d[i][j])
		{
//			cerr<<d[i][j]<<' '<<dis[i][j]<<endl;
			return printf("Impossible\n"),0;
		}
	}

	printf("Possible\n");
	printf("%d %d\n",202,tot);	
	for(int i=1;i<=202;i++)
	{
		for(int j=head[i];j;j=nex[j])
		{
			cout<<i<<" "<<to[j]<<" "<<val[j]<<endl;
		}
	}
	printf("1 202\n");
}
