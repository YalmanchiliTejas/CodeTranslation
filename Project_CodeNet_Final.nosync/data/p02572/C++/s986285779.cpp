#include <bits/stdc++.h>
using namespace std;

int main() {
	//cout<<"GfG!";
	long long int n;
	cin>>n;
	long long int arr[n],i=0,sum=0,answer=0,mod=pow(10,9)+7;
	while(i<n)
	{
	    cin>>arr[i];
	    sum+=arr[i];
	    i++;
	}
	i=0;
	while(i<n-1)
	{
	    long long int c=sum-arr[i];
	    c%=mod;
	    answer=(answer+(arr[i]*c)%mod)%mod;
	    sum-=arr[i];
	    i++;
	}
	cout<<answer<<endl;
	return 0;
}