#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 305
#define INF 0x3fffffff
int f[N][N];
int d[N][N];
bool check(int x,int y,int v)
{
	int res=INF;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(f[i][j]>=0)
			{
				res=min(res,i*x+j*y+f[i][j]);
			}
		}
	}
	return res==v;
}
signed main()
{
	memset(f,-1,sizeof(f));
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			d[i][j]=read();
		}
	}
	int sum=0;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			int tmp=-INF;
			for(int c=1;c<=a;c++)
			{
				for(int e=1;e<=b;e++)
				{
					tmp=max(tmp,d[c][e]-i*c-j*e);
				}
			}
			f[i][j]=tmp;
			if(f[i][j]<0) break;
			sum++;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(!check(i,j,d[i][j]))
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	int s=201,t=202;
	printf("Possible\n");
	printf("%d %d\n",202,sum+200);
	for(int i=1;i<100;i++)
	{
		printf("%d %d X\n",i,i+1);
		printf("%d %d Y\n",i+101,i+100);
	}
	printf("%d %d X\n",s,1);
	printf("%d %d Y\n",101,t);
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(f[i][j]>=0)
			{
				printf("%d %d %d\n",i==0?s:i,j==0?t:j+100,f[i][j]);
			}
		}
	}
	printf("%d %d\n",s,t);
	return 0;
}

