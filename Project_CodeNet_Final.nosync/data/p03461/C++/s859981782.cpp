#include<bits/stdc++.h>
using namespace std;
int read( ){
	int x=0,y=1;char ch=' ';
	for(;(ch!='-' && (ch>'9' || ch<'0'));ch=getchar( ));
	if(ch=='-')y=-1,ch=getchar( );
	for(;ch>='0' && ch<='9';ch=getchar( ))x=x*10+ch-48;
	return x*y;
}
const int N=1e3+10;
int n,m;
int d[N][N],f[N][N];
int main( ){
	int x,y,z,k;
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
			d[i][j]=read();
	for(register int i=0;i<=100;++i)
		for(register int j=0;j<=100;++j)
			for(register int x=1;x<=n;++x)
				for(register int y=1;y<=m;++y)
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
	for(register int x=1;x<=n;++x)
		for(register int y=1;y<=m;++y){
			int mn=1000;
			for(register int i=0;i<=100;++i)
				for(register int j=0;j<=100;++j)
					mn=min(mn,i*x+j*y+f[i][j]);
			if(mn!=d[x][y]){
				puts("Impossible");return 0;
			}
		}
	puts("Possible");
	printf("202 %d\n",200+101*101);
	for(register int i=1;i<=100;++i)
		printf("%d %d X\n",i,i+1);
	for(register int i=102;i<=201;++i)
		printf("%d %d Y\n",i,i+1);
	for(register int i=0;i<=100;++i)
		for(register int j=0;j<=100;++j)
			printf("%d %d %d\n",i+1,202-j,f[i][j]);	
	puts("1 202");
	return 0;
}
/*
1<=x<=n  1<=y<=m 
f[i][j] :经过 i 个 x,j 个 y,其它边和的最小值 
d[x][y] = min( i * x + j * y + f[i][j] )
d[x][y] <= i * x + j * y + f[i][j]
f[i][j] >= d[x][y] - i * x - j * y

f[i][j] = max( d[x][y] - i * x - j * y )
这样可能存在 dR[x][y] > d[x][y]
但每个 f[i][j] 都存在一组 x,y dR[x][y]=d[x][y]
所以 f[i][j] 不能调小，此时 impossible 

*/