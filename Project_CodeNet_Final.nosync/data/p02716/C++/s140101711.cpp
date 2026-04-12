#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200003],b[200003],fsum[200003],bsum[200003],ans=-2e18,sum,su;
signed main()
{
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	fsum[1]=a[1],fsum[2]=a[2],bsum[n]=a[n],bsum[n-1]=a[n-1];
	for(int i=3; i<=n; i++)
		fsum[i]=fsum[i-2]+a[i];
	for(int i=n-2; i>=1; i--)
		bsum[i]=bsum[i+2]+a[i];
	sum=fsum[n];
	if(n%2==0)
	{
		ans=max(fsum[n-1],fsum[n]);
		for(int i=1; i<=n; i+=2)
			ans=max(ans,fsum[i]+bsum[i+3]);
		cout<<ans;
		return 0;
	}
	for(int i=1; i<=n; i++)
		if(i%2==1)
			b[i]=-a[i];
		else
			b[i]=a[i];
	for(int i=1; i<=n; i++)
		if(i%2==0)
			su+=b[i];
		else
		{
			if(su<0)
				su=b[i];
			else
				su+=b[i];
			ans=max(ans,sum+su);
		}
	cout<<ans;
	return 0;
}