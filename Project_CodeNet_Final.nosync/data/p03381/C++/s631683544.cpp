#include<iostream>
#include<algorithm>
using namespace std;
int n,a[2<<17],b[2<<17];
main()
{
	cin>>n;
	for(int i=0;i<n;b[i]=a[i],i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)cout<<a[a[n/2]>b[i]?n/2:n/2-1]<<endl;
}
