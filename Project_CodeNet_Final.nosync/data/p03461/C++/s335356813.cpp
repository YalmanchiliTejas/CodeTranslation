#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 205

int n,m,A,B;
int d[maxn][maxn],f[maxn][maxn];

inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	A=read(),B=read();
	for (int i=1;i<=A;i++)
		for (int j=1;j<=B;j++)
			d[i][j]=read();
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++)
			for (int a=1;a<=A;a++)
				for (int b=1;b<=B;b++)
					f[i][j]=max(f[i][j],d[a][b]-i*a-j*b);
	for (int a=1;a<=A;a++)
		for (int b=1;b<=B;b++){
			int res=1e9;
			for (int i=0;i<=100;i++)
				for (int j=0;j<=100;j++)
					res=min(res,f[i][j]+i*a+j*b);
			if (res!=d[a][b]){puts("Impossible"); return 0;}
		}
	puts("Possible");
	n=202,m=10401; printf("%d %d\n",n,m);
	for (int i=1;i<(n>>1);i++) printf("%d %d X\n",i,i+1);
	for (int i=(n>>1)+1;i<n;i++) printf("%d %d Y\n",i,i+1);
	for (int i=1;i<=(n>>1);i++)
		for (int j=(n>>1)+1;j<=n;j++)
			printf("%d %d %d\n",i,j,f[i-1][n-j]);
	printf("%d %d\n",1,n);
	return 0;
}
