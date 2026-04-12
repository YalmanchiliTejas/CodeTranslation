#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <functional>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int mod=pow(10,9)+7;
	
	vector<int> arr;
	arr.resize(n,0);
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum=sum+arr[i];
	}
	sum=sum%mod;
	long long res=0;
	
	for(int i=0;i<n;i++)
	{
		sum=sum-arr[i];
		sum=(sum+mod)%mod;
		res=res+arr[i]*(sum%mod);
		res=res%mod;
	}
	cout<<res<<endl;
	return 0;
}