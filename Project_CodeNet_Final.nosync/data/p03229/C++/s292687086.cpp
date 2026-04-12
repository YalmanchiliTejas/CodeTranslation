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
		sum=a[mid]-a[mid-1];
		for(i=0;i<mid-1;++i)
			sum-=2*a[i];
		for(i=mid+1;i<n;++i)
			sum+=2*a[i];
		cout<<sum;
	}
	return 0;
}