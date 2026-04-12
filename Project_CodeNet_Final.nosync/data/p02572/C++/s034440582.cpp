#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20,MOD=1e9+7;

int n,a[N];
long long s,ans;

int mul(int a,int b)
{
	b%=MOD;
	if(b<0) b+=MOD;
	return (1ll*a*b)%MOD;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}

	s%=MOD;
	for(int i=0;i<n;i++)
	{
		ans+=mul(a[i],s-a[i]);
		ans%=MOD;

		s-=a[i];
		s%=MOD;
		if(s<0) s+=MOD;
	}

	cout<<ans;
}