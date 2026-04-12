#include<cstdio>

using namespace std;

int n,ms[15][15];

void solve(int x,int y,int i)
{
	if(i>n*n)	return;
	if(n<=x)		solve(0,y,i);
	else if(x<0)	solve(n-1,y,i);
	else if(n<=y)	solve(x,0,i);
	else if(ms[y][x]!=0)	solve(x-1,y+1,i);
	else		ms[y][x]=i,	solve(x+1,y+1,i+1);
}

int main()
{
	for(;scanf("%d",&n),n;){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)ms[i][j]=0;
		solve(n/2,n/2+1,1);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)printf("%4d",ms[i][j]);
			puts("");
		}
	}
	return 0;
}