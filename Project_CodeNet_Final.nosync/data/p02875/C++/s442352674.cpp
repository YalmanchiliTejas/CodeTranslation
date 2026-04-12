#include <stdio.h>
const int MOD=998244353;
const int N=1e7+10;
long long int f[N],inf[N];
long long int POW(long long int a,long long int b){
	long long int ans=1;
	while(b){
		if(b&1)ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}
long long int Inv(long long int n){return POW(n,MOD-2);}
long long int C(long long int n,long long int m){return (f[n]*((inf[m]*inf[n-m])%MOD))%MOD;}
void pre(){
	inf[0]=inf[1]=f[0]=f[1]=1;
	for(int i=2;i<N;i++)f[i]=(f[i-1]*i)%MOD;
	inf[N-1]=Inv(f[N-1]);
	for(int i=N-2;i>=2;i--)inf[i]=(inf[i+1]*(i+1))%MOD;
	return ;
}
int main(){
	pre();
	int n;
	long long int ans=0,temp;
	scanf("%d",&n);
	ans=POW(3,n);
	for(int i=n/2+1;i<=n;i++){
		temp=POW(2,n-i+1);
		temp=(temp*C(n,i))%MOD;
		ans=(ans-temp+MOD)%MOD;
	}
	printf("%lld\n",ans);
}
