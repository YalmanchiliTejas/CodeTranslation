#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;

const int N=61;

ll sum,a[N],n,k,b[N];

bool ok()
{
	for(int i=1;i<=n;i++)
		if(b[i]>n-1)
			return true;
	return false;
}

bool check(ll m)
{
	ll tm=0;
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	while(ok())
	{
		ll tmp=0;
		for(int i=1;i<=n;i++)
			tmp+=b[i]/n;
		for(int i=1;i<=n;i++)
			b[i]=(tmp-b[i]/n)+(b[i]%n);
		tm+=tmp;
		if(tm>m)
			return 0;
	}
	return true;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	ll l=-1,r=sum;
	while(r-l>1)
	{
		ll mid=(l+r)>>1;
		if(!check(mid))
			l=mid;
		else
			r=mid;
	}
	cout<<r;
}