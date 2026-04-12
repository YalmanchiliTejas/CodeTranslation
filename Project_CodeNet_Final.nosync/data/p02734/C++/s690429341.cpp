#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll dp[3005],n,s,a[3005];
const ll mod=998244353;

int main()
{
	n=read(); s=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=s;i++) dp[i]=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=s;j>=a[i];j--)
		{
			if(j==a[i]) dp[j]=(dp[j]+i)%mod;
			else dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		ans=(ans+(n-i+1)*dp[s]%mod)%mod; dp[s]=0;
	}
	cout<<ans<<endl;
	return 0;
}