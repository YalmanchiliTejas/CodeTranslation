#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=998244353;
int main()
{
	ll i,j,k,m,n,t,x;
	cin>>n>>x>>m;
	ll ar[100001];
	ar[0]=x;
	map<ll,ll> mp;
	mp[x]=1;
	ll ans=x,c1=1;
	for(i=1;i<n;i++)
	{
		x=ar[i-1]*ar[i-1];
		x%=m;
		if(mp[x]) break;
		mp[x]++;
		c1++;
		ar[i]=x;
		ans+=x;
	}
	n-=c1;
	ll s=0;
	for(j=0;j<c1;j++)
	if(ar[j]==x) break;
	ll ctr=0;
	ll pos=j;
	for(;j<c1;j++)
	{
		s+=ar[j];
		ctr++;
	}
	ans+=(n/ctr)*s;
	n%=ctr;
	i=pos;
	while(n--)
	{
		ans+=ar[i];
		i++;
	}
	cout<<ans;
}