#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);++(i))
using namespace std;
const int mod=998244353,maxn=16384;
int n,m,i,j,rev[maxn+5],a[maxn+5],b[maxn+5],dp[505][maxn+5],w[maxn+5],fac[maxn+5],inv[maxn+5],fi[maxn+5];
int c(int x,int y){
	if(x<y||x<0||y<0) return 0;
	return 1ll*fac[x]*fi[y]%mod*fi[x-y]%mod;
}
int pw(int x,int y){
	int z=1;
	while(y){
		if(y&1){
			z=1ll*z*x%mod;
		}
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
void init(){
	int i;
	inv[1]=w[0]=1;w[1]=pw(3,(mod-1)/maxn);fac[0]=fac[1]=fi[0]=fi[1]=1;
	for(i=2;i<=maxn;i++){
		w[i]=1ll*w[i-1]*w[1]%mod;
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod;
	}
}
int getrev(int x){
	int l=1;
	while(l<=x) l=l+l;
	for(i=0;i<l;i++){
		rev[i]=rev[i/2]/2+((i&1)*(l/2));
	}
	return l;
}
void ntt(int *a,int len,int op){
	int i,j,k;
	for(i=0;i<len;i++)if(rev[i]<i) swap(a[i],a[rev[i]]);
	for(i=1;i<len;i<<=1){
		int ys=maxn/i/2;
		for(j=0;j<len;j+=i+i){
			int t=(op==1?0:maxn);
			for(k=0;k<i;k++){
				int x=a[j+k],y=1ll*w[t]*a[j+k+i]%mod;
				a[j+k]=(x+y)%mod;
				a[j+k+i]=(x-y+mod)%mod;
				t+=op*ys;
			}
		}
	}
	if(op==-1){
		for(i=0;i<len;i++){
			a[i]=1ll*a[i]*inv[len]%mod;
		}
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	dp[0][0]=1;
	int len=getrev(n+n+2);
	rep(i,m){
		for(j=0;j<len;j++){
			a[j]=b[j]=0;
		}
		for(j=0;j<=n;j++){
			a[j]=1ll*dp[i-1][j]*fi[j]%mod;
			if(j==0) b[j]=0; else b[j]=fi[j+2];
		}
		ntt(a,len,1);ntt(b,len,1);
		for(j=0;j<len;j++){
			a[j]=1ll*a[j]*b[j]%mod;
		}
		ntt(a,len,-1);
		for(j=0;j<=n;j++){
			dp[i][j]=(1ll*a[j]*fac[j+2]%mod+1ll*dp[i-1][j]*(1+c(j+1,2))%mod)%mod;
		}
	}
	int ans=0;
	for(i=0;i<=n;i++){
		ans=(ans+1ll*dp[m][i]*c(n,i))%mod; 
	}
	printf("%d\n",ans);
	return 0;
}