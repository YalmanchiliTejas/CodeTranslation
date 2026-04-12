#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
int n;s64 a[55];
s64 check(const s64 &s)
{
	s64 ns=0;
	for(int i=1;i<=n;++i)ns+=(a[i]+s+1)/(n+1);
	return ns;
}

int main()
{
	cin>>n;
	s64 sum=0;
	for(int i=1;i<=n;++i){cin>>a[i];sum+=a[i];}
	s64 limit=sum-n*(n-1);
	s64 l=0,r=sum;
	if(check(l)<limit)
	{
		while(l+1!=r)
		{
			s64 mid=(l+r)/2;
			if(check(mid)<=limit)l=mid;
			else r=mid;
		}
	}
	s64 ans=check(l);
	for(int i=1;i<=n;++i)
	{
		s64 b=(a[i]+l+1)/(n+1);
		a[i]=a[i]-(n+1)*b+ans;
	}
	while(1)
	{
		s64 *it=max_element(a+1,a+n+1);
		if(*it<n)break;
		++ans;
		for(int i=1;i<=n;++i)++a[i];
		*it-=n+1;
	}
	cout<<ans;
}