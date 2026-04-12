#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
main()
{
	//freopen("input.txt","rt",stdin);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int arr1[n];
	arr1[n-1] = arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		arr1[i] = arr[i] + arr1[i+1];
		arr1[i] %= mod;
	}
	int sum =0;
	for(int i=0;i<n-1;i++)
	{
		int m = arr[i] * arr1[i+1]; 
		m %= mod;
		sum += m;
		sum %=mod;
	}
	cout<<sum<<endl;
}