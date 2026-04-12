#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define re register
#define N 3010
#define id(x,y) (y?102+x:1+x)
using namespace std;

inline int read(){
	int x=0,w=0;char ch=getchar();
	while (!isdigit(ch))w|=ch=='-',ch=getchar();
	while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return w?-x:x;
}
int n,m,d[N][N],f[N][N];
signed main(){
	n=read(),m=read();
	for (int i=1;i<=n;++i)	
		for (int j=1;j<=m;++j)
			d[i][j]=read();
	for (int i=0;i<=100;++i)
		for (int j=0;j<=100;++j)
			for (int x=1;x<=n;++x)
				for (int y=1;y<=m;++y)
					f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
	for (int x=1;x<=n;++x)
		for (int y=1;y<=m;++y){
			int mn=inf;
			for (int i=0;i<=100;++i)
				for (int j=0;j<=100;++j)
					mn=min(mn,f[i][j]+i*x+j*y);
			if (mn!=d[x][y]){puts("Impossible");return 0;}
		}
	puts("Possible");
	printf("%d %d\n",id(100,1),10401);
	for (int i=1;i<=100;++i)printf("%d %d X\n",id(i-1,0),id(i,0));
	for (int i=1;i<=100;++i)printf("%d %d Y\n",id(i-1,1),id(i,1));
	for (int i=0;i<=100;++i)
		for (int j=0;j<=100;++j)
			printf("%d %d %d\n",id(i,0),id(100-j,1),f[i][j]);
	printf("%d %d\n",1,id(100,1));
	return 0;
}
