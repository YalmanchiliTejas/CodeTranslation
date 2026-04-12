#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define li int64_t
#define m 1000000007

int main()
{
	int n;
	cin>>n;
	li a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	li prefixsum[n];
	prefixsum[0] = a[0];
	for(int i=1;i<n;i++)
	{
		prefixsum[i] = prefixsum[i-1]+a[i];
	}
	li sum =0;
	for(int i=0;i<n-1;i++)
	{
		sum+= (a[i]) * ((prefixsum[n-1]-prefixsum[i]) % m);
		sum = sum % m;
	}
	cout<<sum % m ;

}