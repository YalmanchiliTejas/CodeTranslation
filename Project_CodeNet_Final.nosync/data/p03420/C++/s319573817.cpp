#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long n,k;
	cin>>n>>k;
	long long ans=0LL;
	for (long long i = k+1; i <= n; ++i)
	{
		ans+=((n+1LL)/i)*(i-k);
		ans+=max(0LL,((n+1LL)%i)-k);
	}
	if (k==0)
	{
		ans-=n;
	}
	cout<<ans<<endl;
	return 0;
}
