#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int dp[8005][205];
int n,m,len,L,Inv;
int fac[8005],ifac[8005];
int f[40005],g[40005],R[40005];

int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod,y/=2;
	}
	return res;
}

int C(int x,int y){
	if(x<y) return 0;
	int res=1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
	return res;
}

void NTT(int *x,int on){
	for(int i=0;i<len;i++) if(i<R[i]) swap(x[i],x[R[i]]);
	for(int i=2;i<=len;i*=2){
		int wn=ksm(3,(mod-1)/i);
		if(on==-1) wn=ksm(wn,mod-2);
		for(int j=0;j<len;j+=i){
			int w=1;
			for(int k=0;k<i/2;k++){
				int u=x[j+k],v=1ll*w*x[j+k+i/2]%mod;
				x[j+k]=(u+v)%mod;
				x[j+k+i/2]=(u-v+mod)%mod;
				w=1ll*w*wn%mod;
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	dp[0][0]=1;
	fac[0]=1;for(int i=1;i<=n+2;i++) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n+2]=ksm(fac[n+2],mod-2);
	len=1,L=0;
	while(len<=2*n) len*=2,L++;
	for(int i=0;i<len;i++) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	Inv=ksm(len,mod-2);
	for(int i=n+1;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int j=1;j<=m;j++){
		for(int i=0;i<=n;i++) dp[i][j]=1ll*dp[i][j-1]*(1+i+C(i,2))%mod;
		memset(f,0,sizeof(f));for(int i=0;i<=n;i++) f[i]=1ll*dp[i][j-1]*ifac[i]%mod;
		memset(g,0,sizeof(g));for(int i=1;i<=n;i++) g[i]=ifac[i+2];
		NTT(f,1),NTT(g,1);
		for(int i=0;i<len;i++) f[i]=1ll*f[i]*g[i]%mod;
		NTT(f,-1);
		for(int i=0;i<len;i++) f[i]=1ll*f[i]*Inv%mod;
		for(int i=0;i<=n;i++) (dp[i][j]+=1ll*fac[i+2]*f[i]%mod)%=mod;
	}
	int ans=0;
	for(int i=0;i<=n;i++) (ans+=1ll*C(n,i)*dp[i][m]%mod)%=mod;
	printf("%d\n",ans);

	return 0;
}