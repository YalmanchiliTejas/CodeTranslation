#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],n,tot;
const ll mod=1000000007;

inline ll pw(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=(ans*base)%mod;
		base=(base*base)%mod; b>>=1;
	}
	return ans;
}

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),tot=(tot+a[i])%mod;
	tot=(tot*tot)%mod;
	rep(i,1,n)
	{
		ll tmp=(a[i]*a[i])%mod;
		tot=(tot-tmp+mod)%mod;
	}
	ll p=pw(2,mod-2); tot=(tot*p)%mod; cout<<tot<<endl;
	return 0;
}