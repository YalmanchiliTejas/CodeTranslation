#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf (1ll<<60) 
#define r register
inline bool isd(r char ch) {
	return ch<='9'&&ch>='0';
}
template<class temp>
inline temp F() {
	r temp x=0;
	r bool bo=0;
	r char ch=getchar();
	while(ch!='-'&&!isd(ch))
		ch=getchar();
	(ch=='-')&&(bo=1,ch=getchar());
	x=ch^'0',ch=getchar();
	while(isd(ch))
		x=(x<<1)+(x<<3)+(ch^'0'),ch=getchar();
	bo&&(x=-x);
	return x;
}
const int mod=998244353;
int Qpow(r int x,r int y) {
	r int ret=1;
	while(y) {
		if(y&1)
			ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int fac[20001],ifc[20001],inv[20001];
int lim=1,lg=0;
int G[2][25];
int p[100001];
int f[100001],g[100001];
inline int Add(r int a,r int b) {
	return a+b>=mod?a+b-mod:a+b; 
}
inline int Sub(r int a,r int b) {
	return a-b<0?a-b+mod:a-b;
}
inline int Mul(r int a,r int b) {
	return 1ll*a*b%mod;
}
void Calc() {
	for(r int i=0;i<lim;++i)
		p[i]=(p[i>>1]>>1)|((i&1)<<(lg-1));
}
void NTT(int *x,r bool inv) {
	for(r int i=0;i<lim;++i)
		if(i<p[i])
			std::swap(x[i],x[p[i]]);
	for(r int mid=1,o=1;mid<lim;mid<<=1,++o) {
		r int Wn=G[inv][o];
		for(r int t=mid<<1,i=0;i<lim;i+=t)
			for(r int j=0,w=1;j<mid;++j,w=1ll*w*Wn%mod) {
				r int t1=x[i+j],t2=1ll*x[i+j+mid]*w%mod;
				x[i+j]=Add(t1,t2);
				x[i+j+mid]=Sub(t1,t2);
			}
	}
}
inline int C(r int n,r int m) {
	if(n<m)
		return 0;
	return 1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;
}
int dp[2][10001];
int main() {
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	G[0][23]=Qpow(3,119);
	G[1][23]=Qpow(G[0][23],mod-2);
	for(r int i=22;i;--i) {
		G[0][i]=1ll*G[0][i+1]*G[0][i+1]%mod;
		G[1][i]=1ll*G[1][i+1]*G[1][i+1]%mod;
	}
	r int N=F<int>(),M=F<int>();
	fac[0]=fac[1]=ifc[0]=ifc[1]=inv[1]=1;
	for(r int i=2;i<=N+10;++i) {
		fac[i]=1ll*i*fac[i-1]%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		ifc[i]=1ll*inv[i]*ifc[i-1]%mod;
	}
	r int cur=0;
	for(r int i=0;i<=N;++i)
		dp[cur][i]=1;
	for(r int i=1;i<=N;++i)
		g[i]=ifc[i+2];
	lim=1,lg=0;
	while(lim<=N*2+2)
		lim<<=1,++lg;
	Calc();
	NTT(g,0);
	r int Inv=Qpow(lim,mod-2);
	for(r int i=2;i<=M;++i,cur^=1) {
		memset(dp[cur^1],0,sizeof dp[cur^1]);
		for(r int j=0;j<=N;++j) 
			dp[cur^1][j]=Add(dp[cur^1][j],Mul(dp[cur][j],Add(C(j+1,2),1)));
		memset(f,0,sizeof f);
		for(r int j=0;j<=N;++j)
			f[j]=Mul(dp[cur][j],ifc[j]);
		NTT(f,0);
		for(r int j=0;j<lim;++j)
			f[j]=Mul(f[j],g[j]);
		NTT(f,1);
		for(r int j=0;j<lim;++j)
			f[j]=Mul(f[j],Inv);
		for(r int j=0;j<=N;++j)
			dp[cur^1][j]=Add(dp[cur^1][j],Mul(f[j],fac[j+2]));
	}
	r int ans=0;
	for(r int i=0;i<=N;++i)
		ans=Add(ans,Mul(C(N,i),dp[cur][i]));
	printf("%d\n",ans);
	return 0;
}