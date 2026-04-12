#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,ans,t;
int main()
{
	cin>>n>>k;
	for (long long i=k+1;i<=n;i++)
	{
		ans+=(n/i)*(i-k);
		t=n%i;
		if (t>=k) ans+=(t-k+1);
	}
	if (!k) ans-=n;
	cout<<ans<<endl;
	return 0;
}