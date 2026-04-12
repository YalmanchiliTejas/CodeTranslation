//A,Elebereth Gilthoniel mantae!
//For Temeria!
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<cstdio>
#include<map>
#include<stack>
#include<queue>
#include<cstring> 
using namespace std;
long long a[55];long long ans;long long up[55],down[55],ups,downs;
int main()
{
 	//freopen("","r",stdin);
	//freopen("","w",stdout);
	long long n;cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i];sort(a,a+n);reverse(a,a+n);int dim=500;
	while(dim--)
	{
	for(int i=0;i<n;i++)
	{
		if(a[i]>=n) 
		{
			ans+=a[i]/n;for(int j=0;j<n;j++) if(i!=j) a[j]+=a[i]/n;
			a[i]=a[i]-a[i]/n*n;
	}
	}
}
	while(1)
	{
		downs=ups=0;
		for(long long i=0;i<n;i++)
		{
			if(a[i]>=n) up[ups++]=i;
			else down[downs++]=i;
		}if(ups==0) break;
		long long mi=1e16+2000;
		for(long long i=0;i<ups;i++)
		{
			long long j=up[i];
			mi=min(mi,a[j]);
		}
		int knife=n-ups+1;
		mi=mi/knife;ans+=mi*ups;//cout<<ans;
		for(long long i=0;i<ups;i++)
		{
			long long j=up[i];
			a[j]-=mi*knife;
		}
		for(long long i=0;i<downs;i++)
		{
			long long j=down[i];
			a[j]+=mi*ups;
		}
	}
	cout<<ans<<endl;
	return 0;
}