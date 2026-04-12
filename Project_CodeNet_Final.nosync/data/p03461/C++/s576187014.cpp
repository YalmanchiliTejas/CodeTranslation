#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0; int f=1; char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

const int MAXN = 115;
int mp[MAXN][MAXN],f[MAXN][MAXN];
int n,m;

int main(int argc, char const *argv[])
{
	n=read(),m=read();
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			mp[i][j]=read();
	for(int i=0; i<=100; ++i)
		for(int j=0; j<=100; ++j)
			for(int p=1; p<=n; ++p)
				for(int q=1; q<=m; ++q)
					f[i][j]=max(f[i][j],mp[p][q]-i*p-j*q);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int mn=1e9;
			for(int p=0; p<=100; ++p)
				for(int q=0; q<=100; ++q)
					mn=min(mn,f[p][q]+p*i+q*j);
			if(mn!=mp[i][j])
			{puts("Impossible"); return 0;}
		}
	puts("Possible");
	puts("202 10401");
	for(int i=1; i<=100; ++i)
		printf("%d %d X\n",i,i + 1);
	for(int i=102; i < 202; ++i)
		printf("%d %d Y\n",i,i + 1);
	for(int i=0; i<=100; ++i)
		for(int j=0; j<=100; ++j)
			printf("%d %d %d\n",1+i,202-j,f[i][j]);
	puts("1 202");
	return 0;
}