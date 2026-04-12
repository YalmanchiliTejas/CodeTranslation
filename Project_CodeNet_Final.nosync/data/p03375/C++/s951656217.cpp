#include<cstdio>
#include<iostream>
using namespace std;
int jiang,mod;
long long dp[3001][3001];
long long c[3001][3001];
inline long long quick_pow(long long x,int p,int mod){
	long long result=1;
	while(p){
		if(p&1){
			result*=x;
			result%=mod;
		}
		p>>=1;
		x*=x;
		x%=mod;
	}
	return result;
}
int main(){
	scanf("%d%d",&jiang,&mod);
	for(register int i=0;i<=jiang;i++){
		c[i][0]=dp[i][0]=1;
		for(register int j=1;j<=i;j++){
			dp[i][j]=(dp[i-1][j-1]+(j+1)*dp[i-1][j]%mod)%mod;
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	register long long ans=0;
	for(register int i=0;i<=jiang;i++){
		register long long can=quick_pow(2,quick_pow(2,jiang-i,mod-1),mod);
		register long long num=quick_pow(2,jiang-i,mod);
		register long long sum=0;
		register long long coef=1;
		for(register int j=0;j<=i;j++){
			sum+=dp[i][j]*coef;
			sum%=mod;
			coef*=num;
			coef%=mod;
		}
		ans+=sum*(can*(i&1?mod-c[jiang][i]:c[jiang][i])%mod)%mod;
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}