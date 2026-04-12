#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll dp[5011][10011];
#define SIZE 100000
ll inv[SIZE+1];
ll kai[SIZE+1];
ll invkai[SIZE+1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
int main()
{
	string sa,sb;
	cin>>sa>>sb;
	invinit();
	int c1=0,c2=0;
	for(int i=0;i<sa.size();i++)
	{
		if(sa[i]=='0'&&sb[i]=='1')c1++;
		if(sa[i]=='1'&&sb[i]=='1')c2++;
	}
	dp[0][0]=1;
	for(int i=0;i<=c1;i++)
	{
		for(int j=0;j<=c2;j++)
		{
			dp[i+1][j]=(dp[i+1][j]+(ll)(i+1)*(ll)(i+1)*dp[i][j])%mod;
			dp[i][j+1]=(dp[i][j+1]+(ll)(i)*(ll)(j+1)*dp[i][j])%mod;
			//printf("%lld ",dp[i][j]);
		}
		//printf("\n");
	}
	ll ans=0;
	ll t=1;
	for(int i=0;i<=c2;i++)
	{
		ans+=dp[c1][c2-i]*t%mod*com(c1+c2,i)%mod*com(c2,i);
		ans%=mod;
		t*=(i+1)*(i+1);
		t%=mod;
	}
	printf("%lld\n",ans);
}