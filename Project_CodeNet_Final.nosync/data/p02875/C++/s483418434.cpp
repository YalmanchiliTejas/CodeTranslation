#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int quickpow(int x,int y)
{
	long long res=1,base=x;
	while(y)
	{
		if(y&1) res*=base,res%=mod;
		y>>=1;
		base*=base,base%=mod;
	}
	return res;
}
int inv(int x){return quickpow(x,mod-2);}
int prod[10000001];
int invp[10000001];
int c(int n,int m){return 1ll*prod[n]*invp[m]%mod*invp[n-m]%mod;}
signed main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	prod[0]=1,invp[0]=1;
	for(int i=1;i<=n;i++)
		prod[i]=1ll*prod[i-1]*i%mod,invp[i]=inv(prod[i]);
	for(int i=n/2+((n%2==0)?1:0);i<=n;i++)
		ans+=1ll*c(n,i)*2*quickpow(2,n-i)%mod,ans%=mod;
	printf("%d",((quickpow(3,n)-ans)%mod+mod)%mod);
	return 0;
}
