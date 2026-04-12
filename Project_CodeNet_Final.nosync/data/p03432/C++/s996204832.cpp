#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MN 20005
#define Mod 998244353
int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int n,m;
LL f[205][MN],fac[MN],dfac[MN];
int C(int n,int m){
	if(n>m)return 0;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
int N,r[MN];
LL g[MN],F[MN];
const int G=3,invG=ksm(3,Mod-2);
void NTT(LL f[],int op){
	for(int i=0;i<N;++i)
		if(i<r[i])swap(f[i],f[r[i]]);
	for(register int len=1;len<N;len<<=1){
		int p=len<<1;
		LL tmp=ksm(op?G:invG,(Mod-1)/p);
		for(register int i=0;i<N;i+=p){
			register LL buf=1;
			for(int l=i;l<i+len;++l){
				register LL TMP=buf*f[l+len]%Mod;
				f[l+len]=(f[l]-TMP+Mod)%Mod;
				f[l]=(f[l]+TMP)%Mod;
				buf=buf*tmp%Mod;
			}
		}
	}
	if(!op){
		int invn=ksm(N,Mod-2);
		for(int i=0;i<N;++i)
			f[i]=f[i]*invn%Mod;
	}
}
int main(){
//	freopen("matrix.in","r",stdin);
//	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[0][0]=1;
	N=1;
	while(N<=n*2+2)N<<=1;
	fac[0]=1;for(int i=1;i<=N;++i)fac[i]=fac[i-1]*i%Mod;
	dfac[N]=ksm(fac[N],Mod-2);
	for(int i=N-1;i>=0;--i)dfac[i]=dfac[i+1]*(i+1)%Mod;
	for(int i=0;i<N;++i)r[i]=(r[i>>1]>>1)|((i&1)?(N>>1):0);
	for(int i=1;i<=n;++i)g[i]=dfac[i+2];
	NTT(g,1);
	for(int i=1;i<=m;++i){
		for(int j=0;j<=N;++j)
			F[j]=f[i-1][j]*dfac[j]%Mod;
		NTT(F,1);
		for(int j=0;j<=N;++j)
			F[j]=F[j]*g[j]%Mod;
		NTT(F,0);
		for(int j=0;j<=n;++j){
			f[i][j]=f[i-1][j]*(1+j+C(2,j));
			f[i][j]=(f[i][j]+F[j]*fac[j+2])%Mod;
		}
	}
	LL ans=0;
	for(int i=0;i<=n;++i){
		ans=(ans+f[m][i]*C(i,n))%Mod;
	}
	printf("%lld",ans);
	return 0;
}
