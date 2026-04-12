#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long n;
vector<long>a;
long ans;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long x;cin>>x;a.push_back(x);
	}
	while(1)
	{
		sort(a.begin(),a.end(),greater<long>());
		if(a[0]<n)break;
		long k=0;
		while(k+1<n&&a[k+1]+k+1>=n&&a[k]-a[k+1]<n+1)k++;
		if(k==n-1)
		{
			k=0;
			while(k+1<n&&a[k+1]+k+1>=n&&a[0]-a[k+1]<=k+1)k++;
		}
		if(k<n-1)
		{
			long L=(a[0]-a[k+1])/(1+n);
			if(L<=0)L=1;
			ans+=L*(k+1);
			for(int i=0;i<n;i++)
			{
				if(i>k)a[i]+=L*(k+1);
				else a[i]+=L*(k-n);
			}
		}
		else
		{
			long L=a[0]-n+1;
			if(L>a[n-1])L=a[n-1];
			ans+=L*n;
			for(int i=0;i<n;i++)a[i]-=L;
		}
	}
	cout<<ans<<endl;
}