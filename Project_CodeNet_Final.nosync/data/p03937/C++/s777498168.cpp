#include <bits/stdc++.h>
using namespace std;
int h,w,sum=0;
bool end={false};
string p[10][10];
string ppp[10];
void dfs(int x,int y,int sum1)
{
	if (end==true)
	{
		return;
	}
	if (x==h && y==w && sum1==sum)
	{
		cout <<"Possible";
		end=true;
		return;
	}
	if (x==h && y==w && sum1!=sum)
	{
		cout <<"Impossible";
		end=true;
		return;
	}
	if ((p[x+1][y]=="." && p[x][y+1]==".") || (x+1>h && p[x][y+1]==".") || (y+1>w && p[x+1][y]=="."))
	{
		cout <<"Impossible";
		end=true;
		return;
	}
	if (p[x+1][y]=="#" && p[x][y+1]=="#")
	{
		cout <<"Impossible";
		end=true;
		return;
	}
	if (p[x+1][y]=="#")
	{
		dfs(x+1,y,sum1+1);
	}
	if (p[x][y+1]=="#")
	{
		dfs(x,y+1,sum1+1);
	}
}
int main()
{
	cin>>h>>w;
	for (int i=1; i<=h; i++)
	{
		cin>>ppp[i];
	}
	for (int i=1; i<=h; i++)
	{
		for (int j=1; j<=w; j++)
		{
			p[i][j]=ppp[i].substr(j-1,1);
			if (p[i][j]!="#")
			{
				p[i][j]=".";
			}
			if (p[i][j]=="#")
			{
				sum++;
			}
		}
	}
	dfs(1,1,1);
	return 0;
}