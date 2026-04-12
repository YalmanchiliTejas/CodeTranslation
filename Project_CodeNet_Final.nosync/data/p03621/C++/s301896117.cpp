#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cassert>
#include<cstring>
#define llong long long
using namespace std;

const int N = 2e4;
const int P = 998244353;
const llong INV2 = 499122177;
llong fact[N+3],finv[N+3];

llong quickpow(llong x,llong y)
{
	llong cur = x,ret = 1ll;
	for(int i=0; y; i++)
	{
		if(y&(1ll<<i)) {y-=(1ll<<i); ret = ret*cur%P;}
		cur = cur*cur%P;
	}
	return ret;
}
llong mulinv(llong x) {return quickpow(x,P-2);}
llong comb(llong x,llong y) {return x<0||y<0||x<y ? 0ll : fact[x]*finv[y]%P*finv[x-y]%P;}

int n,a,b;
char s[N+3],t[N+3];
llong dp[2][N+3];

int main()
{
	fact[0] = 1ll; for(int i=1; i<=N; i++) fact[i] = fact[i-1]*i%P;
	finv[N] = quickpow(fact[N],P-2); for(int i=N-1; i>=0; i--) finv[i] = finv[i+1]*(i+1)%P;
	scanf("%s%s",s+1,t+1); n = strlen(s+1);
	for(int i=1; i<=n; i++)
	{
		if(s[i]=='1' && t[i]=='1') {a++;}
		else if(s[i]^t[i]) {b++;}
	}
	b>>=1;
	int cur = 0,prv = 1;
	dp[0][0] = 1ll;
	for(int j=1; j<=b; j++)
	{
		cur^=1; prv^=1;
		dp[cur][0] = dp[prv][0]*j*j%P;
		for(int i=1; i<=a; i++)
		{
			dp[cur][i] = (dp[prv][i]*j*j+dp[cur][i-1]*i*j)%P;
//			printf("dp[%d][%d]=%lld\n",i,j,dp[cur][i]);
		}
	}
	llong ans = 0ll;
	for(int k=0; k<=a; k++)
	{
		ans = (ans+dp[cur][k]*comb(a,k)%P*fact[a-k]%P*fact[a-k]%P*comb(a+b,a-k))%P;
//		printf("k%d ans%lld\n",k,ans);
	}
	printf("%lld\n",ans);
	return 0;
}