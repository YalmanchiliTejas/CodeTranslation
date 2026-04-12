//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define inf 1000000000000000000
#define ff first
#define ss second
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define Clear(x) memset(x,0,sizeof(x))
#define all(x) (x).begin(),(x).end()

void checkpoint1()
{
	/******think more code less******/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

bool comp(pair< ll,ll > &a,pair< ll,ll > &b)
{
	if(a.ff!=b.ff)
		return a.ff<b.ff;
	else
	{
		if(a.ss>b.ss)
			return b.ss<a.ss;
		else if(a.ss<b.ss)
			return a.ss<b.ss;
	}
	return a.ff>b.ff;
}

ll powe(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}

int main()
{
	checkpoint1();
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll b[n];
	b[n-1]=0;
	for(ll i=n-2;i>=0;i--){
		b[i]=b[i+1];
		b[i]+=a[i+1];
		b[i]%=mod;
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		a[i]*=b[i];
		a[i]%=mod;
		ans+=a[i];
		ans%=mod;
	}
	cout<<ans;
	return 0;
}