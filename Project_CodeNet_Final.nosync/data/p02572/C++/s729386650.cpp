#include <bits/stdc++.h> 
using namespace std; 
int main()
{
	long long n;
	cin>>n;
	vector<long long> v;
	long long x;
	long long sum=0;
	long long ms=1e9+7;
	for(long long i=0;i<n;i++)
	{
		cin>>x;
		v.emplace_back(x);
		sum+=x;
		sum%=ms;
	}
	long long s=0;
	long long ans=0;
	for(long long i=0;i<n;i++)
	{
		s+=v[i];
		s%=ms;
		ans+=(v[i]%ms*(sum%ms-s%ms+ms))%ms;
		ans%=ms;
	}
	cout<<ans<<"\n";
}