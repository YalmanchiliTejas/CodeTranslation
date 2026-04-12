#include<bits/stdc++.h>
using namespace std;
const int MAX=3003;

long long ncr[MAX][MAX];
long long dp[MAX][MAX];
int po[MAX*MAX];
int ppo[MAX*MAX];
int pod[MAX*MAX];
typedef long long LL; 
typedef long double LD;
 
int add(int a, int b, int c) {
	int res = a + b;
	return (res >= c ? res - c : res);
}
 
int mod_neg(int a, int b, int c) {
	int res; if(abs(a-b) < c) res = a - b;
	else res = (a-b) % c;
	return (res < 0 ? res + c : res);
}
 
int mul(int a, int b, int c) {
	LL res = (LL)a * b;
	return (res >= c ? res % c : res);
}
 
template <typename T>T power(T e, T n, T m) {
	T x = 1, p = e;
	while(n) {
		if(n & 1) x = mul(x, p, m);
		p = mul(p, p, m);
		n >>= 1;
	}
	return x;
}
 
template<typename T> T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1;
	while(b) {
		T q = a / b, t = b;
		b = a % b; a = t;
		t = xx; xx = x - q * xx;
		x = t; t = yy;
		yy = y - q * yy; y = t;
	}
	return a;
}
 
template<typename T> T mod_inverse(T a, T n) {
	T x, y, z = 0; 
	T d = extended_euclid(a, n, x, y);
	return (d > 1 ? -1 : mod_neg(x, z, n));
}

int main()
{
	int n,MOD;
	scanf("%d %d",&n,&MOD);//scanning n,mod
	ncr[0][0]=1;

	for(int i=1;i<=n;i++)
	{
		ncr[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
		}
	}

	po[0]=1;
	ppo[0]=2;
	pod[0]=1;
	for(int i=1;i<=n;i++)
	{
		po[i]=(po[i-1]*2)%(MOD-1);
		ppo[i]=power(2,po[i],MOD);
	}
	for(int i=1;i<=n*n;i++)
	{
		pod[i]=(pod[i-1]*2)%MOD;
	}
	dp[0][0]=1;
	for(int i=1;i<=(n+1);i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j-1];
			dp[i][j]+=((dp[i-1][j]*j)%MOD);
			dp[i][j]%=MOD;
		}
	}
	long long ans=0;
	for(int i=0;i<=n;i++)
	{
		long long val=0;
		for(int j=0;j<=i;j++)
		{
			val+=((pod[((n-i)*1ll*j)%(MOD-1)]*1ll*dp[i+1][j+1])%MOD);
			val%=MOD;
		}
		val*=ppo[n-i];
		val%=MOD;
		val*=ncr[n][i];
		val%=MOD;
		int sign=((i%2)==0)?1:-1;
		ans+=(sign*val);
		ans+=MOD;
		ans%=MOD;
	//	printf("%lld\n",val);
		
	}
	printf("%lld\n",ans);
}