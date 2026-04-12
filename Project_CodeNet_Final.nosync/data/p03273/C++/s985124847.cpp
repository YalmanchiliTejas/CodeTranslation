#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cassert>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MAXN=101;

int h,w;
char mp[MAXN][MAXN];

int find_r()
{
	for(int i=1;i<=h;i++)
	{
		bool f=1;
		for(int j=1;j<=w;j++) f&=(mp[i][j]=='.');
		if(f) return i;
	}
	return 0;
}

int find_l()
{
	for(int j=1;j<=w;j++)
	{
		bool f=1;
		for(int i=1;i<=h;i++) f&=(mp[i][j]=='.');
		if(f) return j;
	}
	return 0;
}

int main()
{
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++) scanf("%s",mp[i]+1);
	int t;
	while((t=find_r()))
	{
		for(int i=t;i<h;i++)
			for(int j=1;j<=w;j++)
				mp[i][j]=mp[i+1][j];
		h--;
	}
	while((t=find_l()))
	{
		for(int j=t;j<w;j++)
			for(int i=1;i<=h;i++)
				mp[i][j]=mp[i][j+1];
		w--;
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
			printf("%c",mp[i][j]);
		puts("");
	}
}