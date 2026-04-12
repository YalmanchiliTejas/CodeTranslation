#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
const int mod = 998244353;
int n,m,f[201][18010],g1[18010],g2[18010];
ll fac[18010],ifac[18010];
namespace FFT{
	int r[18010],maxn,len;
	ll fp(ll a,ll k){
		ll ans=1;
		for(;k;k>>=1,a=a*a%mod)
			if(k&1) ans=a*ans%mod;
		return ans;
	}
	void build(int n){
		maxn=1;len=0;while(maxn<=n) maxn<<=1,len++;
		for(int i=0;i<maxn;i++) r[i]=r[i>>1]>>1|(i&1)<<len-1;
	}
	int add(int x,int y){return x+y<mod?x+y:x+y-mod;}
	void NTT(int *a,int tag){
		for(int i=0;i<maxn;i++) if(r[i]>i) swap(a[r[i]],a[i]);
		for(int mid=1;mid<maxn;mid<<=1){
			int wn=fp(3,(mod-1)/mid/2);
			if(tag<0) wn=fp(wn,mod-2);
			for(int l=0;l<maxn;l+=mid<<1)
				for(int i=l,w=1;i<l+mid;i++,w=1ll*w*wn%mod){
					int x=a[i],y=1ll*a[i+mid]*w%mod;
					a[i]=add(x,y);a[i+mid]=add(x,mod-y);
				}
		}
		if(tag<0){
			int Inv=fp(maxn,mod-2);
			for(int i=0;i<maxn;i++) a[i]=1ll*a[i]*Inv%mod;
		}
	}
	void mult(int *g1,int *g2,int *g3,int n,int m){
		build(n+m);
		for(int i=n+1;i<maxn;i++) g1[i]=0;
		for(int i=m+1;i<maxn;i++) g2[i]=0;
		NTT(g1,1);NTT(g2,1);
		for(int i=0;i<maxn;i++) g3[i]=1ll*g1[i]*g2[i]%mod;
		NTT(g3,-1);
	}
}
int main(){
	read(n);read(m);
	for(int i=0;i<=n;i++) f[1][i]=1;
	fac[0]=1;
	for(int i=1;i<=n+2;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n+2]=FFT::fp(fac[n+2],mod-2);
	for(int i=n+2;i;i--) ifac[i-1]=ifac[i]*i%mod;
	for(int i=1;i<m;i++){
		for(int j=0;j<=n;j++) g1[j]=1ll*f[i][j]*ifac[j]%mod;
		for(int j=1;j<=n;j++) g2[j]=ifac[j+2];
		g2[0]=0;
		FFT::mult(g1,g2,f[i+1],n,n);
		for(int j=0;j<=n;j++) f[i+1][j]=(1ll*f[i+1][j]*fac[j+2]+1ll*((j+1)*j/2+1)*f[i][j])%mod;
	}
	//for(int i=1;i<=n;i++)
	//	for(int j=1;j<=m;j++)
	//		cout<<i<<' '<<j<<' '<<f[j][i]<<'\n';
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+fac[n]*ifac[i]%mod*ifac[n-i]%mod*f[m][i])%mod;
	cout<<(ans+mod)%mod<<'\n';
	return 0;
}
