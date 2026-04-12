#pragma G++ optimize(2)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define LL long long
#define O4 __inline__ __attribute__((always_inline))
#define inf 0x7fffffff
#define UL unsigned LL
#define LD long double
#ifdef ONLINE_JUDGE
#define getchar nc
#endif
//#define int LL
namespace FastIO{
	O4 char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
	}
	O4 int read(){
		char t;int u=0,k=1;t=getchar();
		while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
		while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
		return u*k;
	}
	template <typename T>
	O4 void read(T &u){
		char t;T k=1;u=0;t=getchar();
		while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
		while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
		if(t=='.'){
			T mass=0.1;t=getchar();
			while(t>='0'&&t<='9'){u+=mass*(t-'0');mass/=10;t=getchar();}
		}u*=k;
	}
	O4 int read(char asd[]){
		char t=getchar();int u=0;
		while(t==' '||t=='\n'||t=='\r')t=getchar();
		while(t!=' '&&t!='\n'&&t!=EOF&&t!='\r')asd[u++]=t,t=getchar();
		asd[u]='\0';return u;
	}
	char sr[1<<23],z[23];int C=-1,Z;
	O4 void wer(int x,char T){
		int y=0;if(x<0)y=1,x=-x;
		while(z[++Z]=x%10+'0',x/=10);if(y)z[++Z]='-';
		while(sr[++C]=z[Z],--Z);sr[++C]=T;
	}
	O4 void wer(char T[],char QWQ){
		for(int i=0;T[i]!='\0';i++)sr[++C]=T[i];
		sr[++C]=QWQ;
	}
	O4 void out(){fwrite(sr,1,C+1,stdout);C=-1;}
}
using namespace std;
using namespace FastIO;
const int N=1e5+5,MOD=1e9+7;
int n,m,a,b,c,d,e,limit,k;
int val[N];struct oath{int F,G;};
//F 黑白相間	G 普通 
O4 int KSM(int a,int b=MOD){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%MOD;
		a=1ll*a*a%MOD;b>>=1;
	}return res;
}
oath DFS(int L,int R,int las,int dp){
	int mi=1e9+5,sum=0;
	oath now={1,1},TP;
	for(int i=L;i<=R;i++){
		if(mi==val[i])sum++;
		if(val[i]<mi)sum=1,mi=val[i];
	}
	if(sum==R-L+1){
		now.F=KSM(2,mi-las);
		now.G=KSM(2,sum)-2;
		return now;
	}
	for(int ql=L,qr;ql<=R;ql=qr+1){
		while(ql<=R&&val[ql]==mi)ql++;
		if(ql==R+1)break;
		qr=ql;while(qr<R&&val[qr+1]>mi)qr++;
		if(ql==L&&qr==R){
			for(int i=L;i<=R;i++)if(val[i]==mi)while(1);
			exit(233);
		}
		TP=DFS(ql,qr,mi,dp+1);
		now.F=1ll*TP.F*now.F%MOD;
		now.G=1ll*(TP.F*2%MOD+TP.G)%MOD*now.G%MOD;
	}
	now.G=1ll*now.G*KSM(2,sum)%MOD;
	(now.G-=now.F*2%MOD)%=MOD;
	now.F=1ll*now.F*KSM(2,mi-las)%MOD;
	return now;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)val[i]=read();
	oath Ans=DFS(1,n,0,1);
	cout<<((Ans.F+Ans.G)%MOD+MOD)%MOD;
	return out(),0;
}
/*
6
1 1 4 5 1 4
*/