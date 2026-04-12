#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
const int mod=1e9+7;

//ll a[maxn];
int main()
{
	ll x;
	vc<ll> a;
	int n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>x,a.push_back(x);
	ll ans=0;
	/*while(true)
	{
		vc<ll> res;
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		dbg(a);
		if(a[0]<n) break;
		++ans;
		res.push_back(a[0]-n);
		for(int i=1;i<(int)a.size();++i)
		{
			res.push_back(a[i]+1);
		}
		a.clear();
		a=res;
	}*/
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	if(a[0]<n) ans=0;
	else
	{
		while(true)
		{
			ll cnt[52],now[52],sum=0;
			bool fl=1;
			for(int i=0;i<n;++i)
			{
				cnt[i]=a[i]/n;
				now[i]=a[i]%n;
				sum+=cnt[i];
				ans+=cnt[i];
			}
			a.clear();
			for(int i=0;i<n;++i)
			{
				a.push_back(now[i]+sum-cnt[i]);
				if(now[i]+sum-cnt[i]>=n) fl=0;
			}
			if(fl) break;
		}
	}
	cout<<ans<<endl;
	
}
