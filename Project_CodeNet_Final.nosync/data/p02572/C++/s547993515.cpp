#include<bits/stdc++.h>
#include<algorithm>
#include<map>
#include<cmath>
#define int long long
#include<string>
#include <vector>


using namespace std;
signed main()
{
int p=1000000007;
	int n,c=0;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b[0]=a[n-1];
	for(int i=n-2;i>=1;i--)
	{
		b[n-i-1] =(b[n-i-2]+a[i])%p	;
	}
	for(int i=0;i<=(n-2);i++)
	{
		c = (c+ (a[i]*b[n-2-i])%p)%p;
	}
	cout<<c;
	
}
