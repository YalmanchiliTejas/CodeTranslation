#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=1e7;
int n,injc[maxn+5],jc[maxn+5],pw[maxn+5],ans;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int C(int n,int k)
{
	return (1ll*jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
void Init()
{
	jc[0]=1;
	for (int i=1;i<=maxn;i++) jc[i]=1ll*jc[i-1]*i%mod;
	injc[maxn]=binpow(jc[maxn],mod-2);
	for (int i=maxn-1;i>=0;i--) injc[i]=1ll*injc[i+1]*(i+1)%mod;
	pw[0]=1;
	for (int i=1;i<=maxn;i++) pw[i]=pw[i-1]*2%mod;
}
int main()
{
	scanf("%d",&n);
	Init();
	for (int i=n/2+1;i<=n;i++)
	{
		ans=(1ll*C(n,i)*pw[n-i+1]+ans)%mod;
	}
	ans=(binpow(3,n)-ans)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}