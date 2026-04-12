#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,x[200001],c,t;
int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=n-1;i>=1;i--)
	{
		x[i]=x[i+1]+a[i+1];
		x[i]%=1000000007;
	}
	for(i=1;i<=n;i++)
	{
		t=(a[i]*x[i])%1000000007; 
		c=(c+t)%1000000007;
	}
	cout<<c<<endl;
	return 0;
}
