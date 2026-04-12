#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,a[123],n,k,b[123];

bool ju()
{
	for(int i=1;i<=n;++i)
	if(b[i]>n-1)return 1;
	return 0;
}

bool can(ll m)
{
	ll ret=0;
	for(int i=1;i<=n;++i)b[i]=a[i];
	while(ju())
	{
		ll cnt=0;
		for(int i=1;i<=n;++i)cnt+=b[i]/n;
		for(int i=1;i<=n;++i)
		b[i]=(cnt-b[i]/n)+(b[i]%n);
		ret+=cnt;
		if(ret>m)
			return 0;
	}
	return 1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
	ll l=-1,r=sum;
	while(r-l>1)
	{
		ll mid=(l+r)>>1;
		if(!can(mid))	l=mid;
		else			r=mid;
	}
	cout<<r;
}