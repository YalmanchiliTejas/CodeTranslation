#include<bits/stdc++.h>
using namespace std;

long long s[200005];

int main()
{
	long long n;
	cin>>n;
	long long a[n+1];
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	
	long long c=0;
	
	for(int i=n;i>=2;i--)
	{
		c+=(a[i]%1000000007)*(s[i-1]%1000000007);
		c=c%1000000007;
	}
	cout<<c;
	return 0;
}