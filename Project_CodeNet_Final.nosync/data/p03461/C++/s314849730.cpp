#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=1e9;
const long double eps=1e-9;
const int maxn=1e2+10;
int d[maxn][maxn],f[maxn][maxn];
inline int read(){
	int x=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')flag=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*flag;
}
int main(){
	int i,j,k,l,m,n;
	int a,b;
	a=read();b=read();
	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++)
			d[i][j]=read();
	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++)
			for(k=0;k<=100;k++)
				for(l=0;l<=100;l++)
					f[k][l]=max(f[k][l],d[i][j]-i*k-j*l);
	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++){
			int dis=INF;
			for(k=0;k<=100;k++)
				for(l=0;l<=100;l++)
					dis=min(dis,f[k][l]+i*k+j*l);
			if(dis!=d[i][j]){
				puts("Impossible");
				return 0;
			}
		}
	n=202,m=101*101+200;
	puts("Possible");
	printf("%d %d\n",n,m);
	for(i=1;i<=100;i++)printf("%d %d X\n",i,i+1);
	for(i=102;i<=201;i++)printf("%d %d Y\n",i,i+1);
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
	printf("%d %d\n",1,n);
	return 0;
}
