#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
const int mod=1e9+7;
const int N=3e5;
int modp(int a,int b)
{
	if(b==0)return 1;
	int u=modp(a,b/2);
	u=(u*u)%mod;
	if(b&1)return (a*u)%mod;
	return u;
}
int inv(int n)
{
	return modp(n,mod-2);
}
int f[N];
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();int m=in();int k=in();
	f[0]=1;
	for(int i=1;i<=n*m;i++)
	f[i]=(f[i-1]*i)%mod;
	
	int base=f[n*m-2];
	base*=inv(f[k-2]);base%=mod;base*=inv(f[n*m-2-(k-2)]);base%=mod;
	
	int ans=0,a;
	for(int i=0;i<n;i++)
	{
		a=i*(n-i);a%=mod;
		a*=(m*m);a%=mod;ans+=a;ans%=mod;
	}
	for(int i=0;i<m;i++)
	{
		a=i*(m-i);a%=mod;
		a*=(n*n);a%=mod;ans+=a;ans%=mod;
	}
	
	cout<<(ans*base)%mod;
	
	
}