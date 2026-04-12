#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,m,k,p[maxn],d,s1,tmp,inv[maxn],fac[maxn];
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

inline ll C(int N,int M)
{
	return ((fac[N]*inv[M])%mod*inv[N-M])%mod;
}

inline ll Mul(ll a,ll b){return (a%mod*b%mod)%mod;}

int main()
{
	cin>>n>>m>>k; fac[0]=1; inv[0]=1;
	for(int i=1;i<=200000;i++) fac[i]=(fac[i-1]*i)%mod;
	for(int i=1;i<=200000;i++) inv[i]=pw(fac[i],mod-2);
	ll ans=0;
	for(ll i=1;i<n;i++) ans=(ans+Mul((n-i)*i,m*m))%mod;
	for(ll i=1;i<m;i++) ans=(ans+Mul((m-i)*i,n*n))%mod;
	ans=(ans*C(n*m-2,k-2))%mod; cout<<ans<<endl;
	return 0;
}