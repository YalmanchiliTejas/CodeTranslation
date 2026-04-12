#include<iostream>
#include<cstdio>
using namespace std;
#define N 10000012
#define mod 998244353
inline int M(int x){return (x>=mod)?(x-mod):x;}
inline int M1(int x){return (x<0)?(x+mod):x;}
inline int ksm(int p,int k){int res=1;while(k){if(k&1)res=1ll*res*p%mod;k>>=1;p=1ll*p*p%mod;}return res;}
int n,fac[N],inv[N],ans,ans1,P[N];
int main(){
	P[0]=1;for(int i=1;i<N;i++)P[i]=M(P[i-1]<<1);
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[N-1]=ksm(fac[N-1],mod-2);for(int i=N-2;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	scanf("%d",&n);ans=ksm(3,n);int i;
	for(i=(n>>1)+1;i<=n;i++)ans1=(ans1+1ll*inv[i]*inv[n-i]%mod*P[n-i])%mod;
	ans1=1ll*ans1*fac[n]%mod;ans=M1(ans-M(ans1<<1));printf("%d",ans);return 0;
}