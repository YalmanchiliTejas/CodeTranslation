#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=3005,mod=998244353;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
int n,m,a[N];
unsigned int f[N][N][3];
inline void add(unsigned int &x,unsigned int y)
{
	x+=y; while(x>=mod) x-=mod;
}
int main()
{
	n=read(); m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	f[0][0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			add(f[i][j][0], f[i-1][j][0]);
			add(f[i][j][1], f[i-1][j][0]+f[i-1][j][1]);
			add(f[i][j][2], f[i-1][j][0]+f[i-1][j][1]+f[i-1][j][2]);
			if(j>=a[i]){
				add(f[i][j][1], f[i-1][j-a[i]][0]+f[i-1][j-a[i]][1]);
				add(f[i][j][2], f[i-1][j-a[i]][0]+f[i-1][j-a[i]][1]);
			}
		}
	}
	printf("%d\n",f[n][m][2]);
	return 0;
}