#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
ll s[maxn];
ll f[maxn];
int main()
{
	ll n;cin>>n;
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
	}
	//ll c=1;
	ll mx=0;
	for(ll c=1;c<n-1;c++)
	{
		ll sz=(n-2)/c;
		unordered_map<ll,ll> mp;
		ll ans=0;
		for(ll k=1;k<=sz;k++)
		{
			if(n-1-k*c-c<=0) break;
			//n-1>=k*c+a,a-b=c>0,a>c
			//n-1-k*c-c should be >0; 
			if(mp.count(n-1-k*c)) break;
			mp[n-1-k*c]++;
			if(mp.count(k*c)) break;
			mp[k*c]++;
			ans+=s[k*c]+s[n-1-k*c];
			mx=max(ans,mx);
		 } 
	}
	cout<<mx<<endl;
}