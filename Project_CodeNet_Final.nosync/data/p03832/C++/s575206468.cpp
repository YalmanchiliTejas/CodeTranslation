#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll fac[1005],dp[1005][1005];
ll pow2(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll get_inv(ll x){
	return pow2(x,mod-2);
}
ll getP(int n,int m){
	return fac[n]*get_inv(fac[n-m])%mod;
}
int main(){
	int N,A,B,C,D;
	scanf("%d%d%d%d%d",&N,&A,&B,&C,&D);
	fac[0]=1;
	for(int i=1;i<=N;i++)
		fac[i]=fac[i-1]*i%mod;
	dp[A-1][0]=1;
	for(int i=A;i<=B;i++){
		for(int j=0;j<=N;j++)
			dp[i][j]=dp[i-1][j];
		for(int k=C;k<=D;k++){
			for(int j=i*k;j<=N;j++){
				dp[i][j]=(dp[i][j]+(dp[i-1][j-i*k]*getP(j,i*k)%mod)*get_inv(pow2(fac[i],k)*fac[k]%mod)%mod)%mod;
			}
		}
	}
	printf("%lld\n",dp[B][N]);
	return 0;
}