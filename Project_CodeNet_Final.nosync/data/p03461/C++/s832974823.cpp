#include"bits/stdc++.h"
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}
int n,m;
int d[12][12],f[110][110];
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;++i)
	for(register int j=1;j<=m;++j)
	d[i][j]=read();
	for(register int i=0;i<=100;++i)
	for(register int j=0;j<=100;++j)
	for(register int x=1;x<=n;++x)
	for(register int y=1;y<=m;++y)
	f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
	int now;
	for(register int x=1;x<=n;++x)
	for(register int y=1;y<=m;++y)
	{
		now=1000000;
		for(register int i=0;i<=100;++i)
		for(register int j=0;j<=100;++j)
		now=min(now,f[i][j]+i*x+j*y);
		if(now!=d[x][y])
		{
			cout<<"Impossible";
			return 0;
		}
	}
	cout<<"Possible"<<endl;
	cout<<202<<" "<<10401<<endl;
	for(register int i=1;i<101;++i)
	printf("%d %d X\n",i,i+1);
	for(register int i=102;i<202;++i)
	printf("%d %d Y\n",i,i+1);
	for(register int i=0;i<=100;++i)
	for(register int j=0;j<=100;++j)
	{
		printf("%d %d %d\n",i+1,202-j,f[i][j]);
	}
	cout<<1<<" "<<202<<endl;
}