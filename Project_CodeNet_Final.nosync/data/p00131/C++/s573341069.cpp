#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int flip[10][10];
int f[10][10];
int ans[10][10];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
int n;
int color(int x,int y)
{
	int res=f[x][y];
	for(int i=0;i<5;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>=10||ny<0||ny>=10)continue;
		res+=flip[nx][ny];
	}
	return res%2;
}
int culc()
{
	for(int i=1;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(color(i-1,j)==1)flip[i][j]=1;
		}
	}
	for(int i=0;i<10;i++)if(color(9,i)==1)return -1;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int s=0;s<n;s++)
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				cin >> f[i][j];
			}
		}
		for(int i=0;i<(1<<10);i++)
		{
			memset(flip,0,sizeof(flip));
			for(int j=0;j<10;j++)flip[0][j]=(i>>j)&1;
			int num=culc();
			if(num<0)continue;
			else goto end;
		}
		end:;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				cout << flip[i][j];
				if(j!=9)cout << ' ';
				else cout << endl;
			}
		}
	}
	return 0;
}