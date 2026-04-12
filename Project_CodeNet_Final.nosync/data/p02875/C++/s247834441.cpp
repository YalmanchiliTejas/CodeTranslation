#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 10000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll fac[maxn],inv[maxn],n,k,ans,nw,q,b[maxn];
const ll mod=998244353;

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

inline ll C(int N,int M){return (fac[N]*inv[M]%mod)*inv[N-M]%mod;}

int main()
{
	fac[0]=1; inv[0]=1; n=read(); b[0]=1;
	rep(i,1,(maxn-5)) fac[i]=(fac[i-1]*i)%mod,b[i]=(b[i-1]*2)%mod;
	rep(i,1,(maxn-5)) inv[i]=pw(fac[i],mod-2); q=pw(3,n); nw=-1;
	for(int i=n/2+1;i<=n;i++)
	{
		ll tmp=C(n,i)*b[n-i]; tmp%=mod;
		ans=(ans+tmp+mod)%mod;
	}
	cout<<(q-(2*ans%mod)+mod)%mod<<endl;
	return 0;
}