#include<bits/stdc++.h>
#define il inline
#define mod 998244353
typedef long long ll;
il int gi(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int fact[8010],ifact[8010];
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
const int G=19260817,iG=pow(G,mod-2);
int dp[16387],New[16387],Dp[16387],rev[16387];
int P[100],iP[100],N,lg;
void setN(int _){
	lg=31-__builtin_clz(_);if(1<<lg!=_)++lg;N=1<<lg;
	for(int i=0;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
}
void ntt(int*A,int t){
	for(int i=0;i<N;++i)if(i>rev[i])std::swap(A[i],A[rev[i]]);
	for(int o=1,w,_=1;o<N;o<<=1,++_){
		w=t?P[_]:iP[_];
		for(int*p=A;p!=A+N;p+=o<<1)
			for(int i=0,W=1;i<o;++i,W=1ll*W*w%mod){
				int t=1ll*p[i+o]*W%mod;
				p[i+o]=(p[i]-t+mod)%mod,p[i]=(p[i]+t)%mod;
			}
	}
	if(!t){
		int inv=pow(N,mod-2);
		for(int i=0;i<N;++i)A[i]=1ll*A[i]*inv%mod;
	}
}
int main(){
// 	freopen("in.in","r",stdin);
// 	freopen("out.out","w",stdout);
	fact[0]=1;for(int i=1;i<8010;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[8009]=pow(fact[8009],mod-2);for(int i=8009;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	int ans=0,n=gi(),m=gi();
	for(int i=0;i<=n;++i)dp[i]=1;
	for(int i=1;(1<<i)<=16384;++i)P[i]=pow(G,mod/(1<<i)),iP[i]=pow(iG,mod/(1<<i));
	setN(n+2<<1);
	for(int i=1;i<=n;++i)New[i]=ifact[i+2];
	ntt(New,1);
	for(int s=2;s<=m;++s){
		memcpy(Dp,dp,sizeof Dp);
		for(int i=0;i<=n;++i)dp[i]=1ll*dp[i]*ifact[i]%mod;
		ntt(dp,1);
		for(int i=0;i<N;++i)dp[i]=1ll*dp[i]*New[i]%mod;
		ntt(dp,0);
		for(int i=0;i<=n;++i)dp[i]=(1ll*dp[i]*fact[i+2]%mod+1ll*Dp[i]*(1ll*(i+1)*i/2%mod+1))%mod;
		for(int i=n+1;i<N;++i)dp[i]=0;
	}
	for(int i=0;i<=n;++i)ans=(ans+1ll*fact[n]*ifact[i]%mod*ifact[n-i]%mod*dp[i])%mod;
	printf("%d\n",ans);
	return 0;
}
