#include<iostream>
using namespace std;
main()
{
	int n,a[200000],b[200000];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int m=n/2;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)b[n/2*2-m--]=a[i];
		else b[m]=a[i];
	}
	if(n%2)for(int i=n;i--;)cout<<b[i]<<(i==0?"\n":" ");
	else for(int i=0;i<n;i++)cout<<b[i]<<(i==n-1?"\n":" ");
}
