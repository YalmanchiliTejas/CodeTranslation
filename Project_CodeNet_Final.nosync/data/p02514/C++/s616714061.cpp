#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<vector>
#include<algorithm>
using namespace std;
struct P{int x,y;P(){}P(int x,int y):x(x),y(y){}};
int Distance(P&l,P&r)
{
	return abs(l.x-r.x)+abs(l.y-r.y);
}
int main()
{
	vector<P>v[2503];
	vector<int>dp[2503];
	P goal;
	int h,w,i,j,k,x,depth;
	char str[512]="";
	while(scanf("%d%d",&w,&h),w)
	{
		for(i=0;i<2503;++i)v[i].clear(),dp[i].clear();
		depth=0;
		for(i=0;i<h;++i)
		{
			for(j=0;j<w;++j)
			{
				while(isspace(str[0]=getchar()));
				if(str[0]=='S')
				{
					v[0].push_back(P(j,i));
					dp[0].push_back(0);
				}
				else if(str[0]=='G')goal=P(j,i);
				else if(isdigit(str[0]))
				{
					for(k=1;isdigit(str[k]=getchar());)++k;
					str[k]=0;
					x=atoi(str);
					depth=max(depth,x);
					v[x].push_back(P(j,i));
					dp[x].push_back(INT_MAX);
				}
			}
		}
		v[depth+1].push_back(goal);
		dp[depth+1].push_back(INT_MAX);

		for(i=1;i<depth+2;++i)
		{
			for(j=0;j<dp[i-1].size();++j)
			{
				for(k=0;k<dp[i].size();++k)
				{
					dp[i][k] = min(dp[i][k],dp[i-1][j]+Distance(v[i-1][j],v[i][k]) );
				}
			}
		}
		printf("%d\n",dp[depth+1][0]);
	}
	return 0;
}