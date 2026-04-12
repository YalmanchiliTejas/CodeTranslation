#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int a[100005],n,i,mid;
	long long sum=0;
	cin>>n;
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	if(n==2)
	{
		cout<<abs(a[0]-a[1]);
		return 0;
	}
	sort(a,a+n);
	mid=n/2;
	if(n%2)
	{
		if(a[mid]-a[mid-1]<a[mid+1]-a[mid])
		{
			for(i=0;i<mid-1;++i)
				sum-=2*a[i];
			sum-=a[mid]+a[mid-1];
			for(i=mid+1;i<n;++i)
				sum+=2*a[i];
		}
		else
		{
			for(i=0;i<=mid-1;++i)
				sum-=2*a[i];
			sum+=a[mid+1]+a[mid];
			for(i=mid+2;i<n;++i)
				sum+=2*a[i];
		}
		cout<<sum;
	}
	else
	{
		int k=0;
		sum=2*a[n-1]-a[0]-a[1];
		for(i=n-2;i>mid;--i)
		{
			sum+=2*a[i]-a[k]-a[k+2];
			++k;
		}
		sum+=a[mid]-a[mid-2];
		cout<<sum;
	}
	return 0;
}