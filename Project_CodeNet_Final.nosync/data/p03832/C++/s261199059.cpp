#include <stdio.h>
#include <string.h>

#define MOD 1000000007

typedef long long lli;

lli dp[1001][1001];
lli n, a, b, c, d;
lli fac[1001], inv[1001];

lli pw(lli n, lli x) {
	if(x==0) return 1;
	if(x%2) return n*pw(n,x-1)%MOD;
	else { lli ret=pw(n,x/2); return ret*ret%MOD; }
}

lli f(lli pre, lli n) {
	if(n==0) return 1;
	if((pre+1)*c>n || pre+1>b) return 0;
	if(dp[pre][n]>=0) return dp[pre][n];
	lli res=f(pre+1,n);
	for(lli i=c;i<=d;i++) {
		if((pre+1LL)*i>n) break;
		res+=(f(pre+1,n-(pre+1LL)*i)*pw(inv[pre+1],i)%MOD)*inv[i]%MOD;
		res%=MOD;
	}
	return dp[pre][n]=res;
}

int main() {
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
	memset(dp,-1,sizeof(dp));
	fac[0]=inv[0]=1;
	for(lli i=1;i<=1000;i++) {
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=pw(fac[i],MOD-2);
	}
	lli res=f(a-1,n)*fac[n]%MOD;
	printf("%lld\n",res);
	return 0;
}