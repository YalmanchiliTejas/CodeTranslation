#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c<'0' || c>'9'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	ll f=1;
	while((c=getchar())!='-' && (c<'0' || c>'9'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int inf=0x3f3f3f3f;
inline bool chkmax(int &x,int y){return (y>x)?(x=y,1):0;}
inline bool chkmin(int &x,int y){return (y<x)?(x=y,1):0;}
int d[11][11],f[101][101];
int main(){
	int A=read(),B=read();
	REP(i,1,A) REP(j,1,B) d[i][j]=read();
	REP(i,0,100) REP(j,0,100)
		REP(x,1,A) REP(y,1,B)
			chkmax(f[i][j],d[x][y]-x*i-y*j);
	REP(x,1,A) REP(y,1,B){
		int dis=inf;
		REP(i,0,100) REP(j,0,100) chkmin(dis,f[i][j]+i*x+j*y);
		if(dis!=d[x][y]){
			printf("Impossible\n");
			return 0;
		}
	}
	int n=202,m=101*101+200;
	printf("Possible\n");
	printf("%d %d\n",n,m);
	REP(i,1,100) printf("%d %d X\n",i,i+1);
	REP(i,102,201) printf("%d %d Y\n",i,i+1);
	REP(i,0,100)
		REP(j,0,100)
			printf("%d %d %d\n",i+1,202-j,f[i][j]);
	printf("%d %d\n",1,n);
	return 0;
}