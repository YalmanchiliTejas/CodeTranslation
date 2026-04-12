#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=3005,Mod=1e9+7;
int dp[N],n,A,B,C,D;
int fac[N],inv[N];
inline int mo(int x){return x<Mod?x:x-Mod;}
inline int qpow(int a,int b){
	int ans=1;
	while (b){
		if (b&1) ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod,b>>=1;
	}
	return ans;
}
inline void init_binom(){
	fac[0]=1;for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%Mod;
	inv[n]=qpow(fac[n],Mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%Mod;
}
inline int Binom(int n,int m){
	return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main (){
	scanf ("%d%d%d%d%d",&n,&A,&B,&C,&D);
	init_binom();
	dp[0]=1;
	for (int i=A;i<=B;i++)
		for (int j=n;j>=0;j--)
			for (int k=C;k<=D&&j+k*i<=n;k++)
				dp[j+k*i]=mo(dp[j+k*i]+
					1ll*dp[j]*Binom(n-j,k*i)%Mod*fac[k*i]%Mod*qpow(inv[i],k)%Mod*inv[k]%Mod
				);
	printf ("%d",dp[n]);
	return 0;
}
