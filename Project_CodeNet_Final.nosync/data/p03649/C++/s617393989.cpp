#include<iostream>
#include<cstdio>
using namespace std;
long long a[55],tot=0;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],tot+=a[i];
	for(long long s=max(tot-10000,0LL);s<=tot+10000;++s)
	{
		long long tot=0;
		for(int i=1;i<=n;++i) tot+=(a[i]+s+1)/(n+1);
		if(tot<=s) return 0*printf("%lld\n",s);	
	}
	return 0;
}

