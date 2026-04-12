#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long int


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(30)<<fixed;

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int b[n];
	b[n-1]=a[n-1];
	int M=1e9+7;
	for(int i=n-2;i>=0;i--)
		b[i]=(b[i+1]+a[i])%M;
	int c=0;
	for(int i=0;i<n-1;i++)
	{
		c=(c+(b[i+1]*a[i])%M)%M;
	}
	cout<<c<<endl;
	return 0;
}
