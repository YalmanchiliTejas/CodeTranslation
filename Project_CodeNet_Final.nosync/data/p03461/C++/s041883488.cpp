#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(int i=(int)(st),i##end=(int)(ed);i<=i##end;++i)
#define DREP(i,st,ed) for(int i=(int)(st),i##end=(int)(ed);i>=i##end;--i)
template<typename T>bool chkmin(T &x,const T &y){return x>y?x=y,1:0;}
template<typename T>bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
template<typename T>T read(){
	T x=0,f=1;
	char c=getchar();
	while((c<'0')||(c>'9')){if(c=='-')f=-1;c=getchar();}
	while((c>='0')&&(c<='9'))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
#define read() read<int>()
template<typename T>void write(T x,char c){
	static char t[25];
	static int tlen;
	t[tlen=1]=c;
	if(x<0)putchar('-'),x=-x;
	do t[++tlen]=(x%10)^48;
	while(x/=10);
	while(tlen)putchar(t[tlen--]);
}
#define pb push_back
typedef long long ll;
typedef double lf;
const int inf=0x3f3f3f3f;
int n,m,A,B,d[15][15],f[105][105];
int main(){
	A=read(),B=read();
	REP(i,1,A)
		REP(j,1,B)
			d[i][j]=read();
	REP(i,0,100)
		REP(j,0,100)
			REP(x,1,A)
				REP(y,1,B)
					chkmax(f[i][j],d[x][y]-i*x-j*y);
	REP(x,1,A)
		REP(y,1,B){
			int dis=inf;
			REP(i,0,100)
				REP(j,0,100)
					chkmin(dis,f[i][j]+i*x+j*y);
			if(dis>d[x][y])return puts("Impossible"),0;
		}
	n=202,m=10401;
	puts("Possible");
	write(n,' '),write(m,'\n');
	REP(i,2,n/2)
		printf("%d %d X\n",i-1,i);
	REP(i,n/2+2,n)
		printf("%d %d Y\n",i-1,i);
	REP(i,0,100)
		REP(j,0,100)
			printf("%d %d %d\n",1+i,n-j,f[i][j]);
	printf("%d %d\n",1,n);
	return 0;
}