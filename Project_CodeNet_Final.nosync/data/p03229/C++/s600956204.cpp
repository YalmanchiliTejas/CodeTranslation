#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	long long arr[100000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
	 } 
	 sort(arr,arr+n);
	 long long sum=0;
	 if(n%2==0)
	 {
	 	for(int i=0;i<n/2-1;i++)
	 	{
	 		sum+=arr[n-i-1];
	 		sum-=arr[i];
		 }
		 sum=sum*2;
		 sum+=arr[n/2];
		 sum-=arr[n/2-1];
	 }
	 else
	 {
	 	for(int i=0;i<n/2-1;i++)
	 	{
	 		sum+=arr[n-i-1];
	 		sum-=arr[i];
		 }
		 sum=sum*2;
		 int a=arr[n/2+1]*2-arr[n/2]-arr[n/2-1];
		 int b=arr[n/2+1]+arr[n/2]-2*arr[n/2-1];
		if(a>b)
		sum+=a;
		else
		sum+=b;
	 }
	 cout<<sum;
 } 