#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<map>
#include<deque>
#include<stack>
#include<algorithm>
#define N 105
using namespace std;
const int INF=0x7fffffff;
const double Pi=acos(-1);
int n,m;
char A[N][N];
bool Check_Row(int x)
{
	int i;
	bool OK=1;
	for(i=1;i<=m;i++)if(A[x][i]!='.')OK=0;
	return OK;
}
bool Check_Con(int y)
{
	int i;
	bool OK=1;
	for(i=1;i<=n;i++)if(A[i][y]!='.')OK=0;
	return OK;
}
void Remove_Row(int x)
{
	//cout<<"Remove_Row"<<x<<endl;
	int i,j;
	for(i=x+1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			A[i-1][j]=A[i][j];
		}
	}
	for(j=1;j<=m;j++)A[n][j]=' ';
	n--;
}
void Remove_Con(int y)
{
	//cout<<"Remove_Con"<<y<<endl;
	int i,j;
	for(j=y+1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
		{
			A[i][j-1]=A[i][j];
		}
	}
	for(i=1;i<=n;i++)A[i][m]=' ';
	m--;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>A[i][j];
		}
	}
	while(1)
	{
		bool OK=0;
		for(i=1;i<=n;i++)if(Check_Row(i)){Remove_Row(i);OK=1;continue;}
		if(OK==1)continue;
		OK=0;
		for(i=1;i<=m;i++)if(Check_Con(i)){Remove_Con(i);OK=1;continue;}
		if(OK==1)continue;
		break;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<A[i][j];
		}
		printf("\n");
	}
	return 0;
}