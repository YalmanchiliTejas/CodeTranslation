#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define pb push_back
#define pii pair<int,int>
#define SZ(x) (int)x.size()
#ifdef __linux__
#define getchar getchar_unlocked
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define  For(i,a,b) for(int i=a,i##E=b;i<=i##E;++i)
#define rFor(i,a,b) for(int i=a,i##E=b;i>=i##E;--i)
typedef long long LL;
using namespace std;
const int N=210;
const int inf=0x3f3f3f3f;
template<typename T>inline bool chkmin(T &a,const T &b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T &a,const T &b){return a<b?a=b,1:0;}
template<typename T>inline void read(T &x)
{
	x=0;int _f(0);char ch=getchar();
	while(!isdigit(ch))_f|=(ch=='-'),ch=getchar();
	while( isdigit(ch))x=x*10+ch-'0',ch=getchar();
	x=_f?-x:x;
}
inline void file()
{
#ifdef ztzshiwo
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
}
int A,B,n,D[N][N],d[N][N],G[N][N];
int main()
{
	file();
	read(A),read(B);
	n=100;
	For(i,1,A)For(j,1,B)read(d[i][j]);
	For(i,0,n)
		For(j,0,n)
			For(a,1,A)
				For(b,1,B)
				{
					//printf("(%d %d %d %d) %d\n",i,j,a,b,d[a][b]-a*i-b*j);
					chkmax(D[i][j],d[a][b]-a*i-b*j);
				}
	For(a,1,A)
		For(b,1,B)
		{
			G[a][b]=inf;
			For(i,0,n)
				For(j,0,n)
					chkmin(G[a][b],D[i][j]+a*i+b*j);
			if(G[a][b]!=d[a][b]){puts("Impossible");exit(0);}
		}
	puts("Possible");
	n=101;
	printf("%d %d\n",2*n,n*n+2*n-2);
	For(i,2,n)printf("%d %d %c\n",i-1,i,'X');
	For(i,2,n)printf("%d %d %c\n",n+i,n+i-1,'Y');
	For(i,1,n)For(j,1,n)printf("%d %d %d\n",i,j+n,D[i-1][j-1]);
	printf("%d %d\n",1,n+1);
	return 0;
}
