#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	long long n,x= 1e9+7,sum=0;
	cin>>n;
	long long a[n],b[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		
	}
	for(int i=n-2;i>=0;i--)
		a[i] += a[i+1];
	for(int i=0;i<n-1;i++)
	{
		sum += ((a[i+1]%x)*(b[i]%x))%x;
		sum %=x;
	}

	cout<<sum%x<<'\n';
    return 0;
		
}