#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=1e5+10,mod=998244353,g0=3;
inline int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return res;
}
int N,n,m;
int dp[205][8005],g[100][2];
int rev[maxn],A[maxn],B[maxn],fac[maxn],ifac[maxn];
inline void ntt(int *y,int flag){
	REP(i,0,N-1) if(i<rev[i]) swap(y[i],y[rev[i]]);
	for(int k=2,t=1;k<=N;k<<=1,++t)
		for(int i=0;i<N;i+=k)
			for(int j=0,x=1;j<(k>>1);++j,x=(ll)x*g[t][flag]%mod){
				int x1=y[i+j],x2=(ll)y[i+j+(k>>1)]*x%mod;
				y[i+j]=(x1+x2)%mod,y[i+j+(k>>1)]=(x1-x2+mod)%mod;
			}
}
int main(){
	n=read(),m=read();
	N=1;
	while(N<=n*2) N<<=1;
	REP(i,0,N-1) rev[i]=(rev[i>>1]>>1)|((i&1)*(N>>1));
	for(int t=0,k=1;k<=N;k<<=1,++t){
		g[t][1]=ksm(g0,(mod-1)/k);
		g[t][0]=ksm(g[t][1],mod-2);
	}
	fac[0]=1;
	REP(i,1,N) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[N]=ksm(fac[N],mod-2);
	DREP(i,N,1) ifac[i-1]=(ll)ifac[i]*i%mod;
	dp[0][0]=1;
	REP(i,1,n) B[i]=ifac[i+2];
	ntt(B,1);
	int inv_N=ksm(N,mod-2);
	REP(i,1,m){
		REP(j,0,N) A[j]=0;
		REP(j,0,n) A[j]=(ll)dp[i-1][j]*ifac[j]%mod;
		ntt(A,1);
		REP(j,0,N-1) A[j]=(ll)A[j]*B[j]%mod;
		ntt(A,0);
		REP(j,0,n) dp[i][j]=((ll)A[j]*inv_N%mod*fac[j+2]+((ll)j*(j+1)/2+1)%mod*dp[i-1][j])%mod;
	}
	int ans=0;
	REP(i,0,n) ans=(ans+(ll)ifac[i]*ifac[n-i]%mod*dp[m][i])%mod;
	ans=(ll)fac[n]*ans%mod;
	printf("%d\n",ans);
	return 0;
}
