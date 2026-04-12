#include<bits/stdc++.h>
using namespace std;
long long M=1000000007;
long long n,a[200005],b[200005],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		b[i]%=M;
	}
	for(int i=2;i<=n;++i)
	 ans=(ans+a[i]*b[i-1])%M;
	cout<<ans;
	return 0;
}