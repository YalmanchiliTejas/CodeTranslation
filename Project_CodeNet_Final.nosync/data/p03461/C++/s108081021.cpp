#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
int d[11][11];
int c[101][101];

int main()
{
	//freopen("1.in","r",stdin);
	int a,b;
	cin>>a>>b;
	rep(i,1,a)
	rep(j,1,b)cin>>d[i][j];
	int n=101+101;
	rep(x,0,100)
	rep(y,0,100)
	{
		rep(i,1,a)
		rep(j,1,b)chmax(c[x][y],d[i][j]-(i*x+j*y));
	}
	rep(i,1,a)
	rep(j,1,b)
	{
		rep(x,0,100)
		rep(y,0,100)
		if(i*x+j*y+c[x][y]==d[i][j])goto have;
		puts("Impossible");
		return 0;
		have : ;
	}
	puts("Possible");
	printf("%d %d\n",n,101*101+100*2);
	rep(x,1,100)printf("%d %d X\n",x,x+1);
	rep(y,1,100)printf("%d %d Y\n",n-y,n-y+1);
	rep(x,0,100)
	rep(y,0,100)printf("%d %d %d\n",1+x,n-y,c[x][y]);
	printf("%d %d\n",1,n);
}