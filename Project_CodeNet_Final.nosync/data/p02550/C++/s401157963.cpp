#include "bits/stdc++.h"
using namespace std;

long long n,x,m;
set <long long> s;
vector <long long> v,vc;

long long cycle_sum(long long x)
{
	long long sum=0;
	set <long long> s;
	vector <long long> v;
	while(s.find(x)==s.end())
	{
		s.insert(x);
		vc.push_back(x);
		sum+=x;
		x=(x*x)%m;
	}
	return sum;
}

int main()
{
	cin>>n>>x>>m;

	if(n<1e6)
	{
		long long s=0;
		for(int i=1;i<=n;i++)
		{
			s+=x;
			x=(x*x)%m;
		}
		cout<<s;
		return 0;
	}

	
	while(s.find(x)==s.end())
	{
		s.insert(x);
		v.push_back(x);
		x=(x*x)%m;
	}
	long long cycle=x;

	if(n<=v.size())
	{
		cout<<accumulate(v.begin(),v.begin()+n,0ll);
		return 0;
	}

	long long csum=cycle_sum(cycle);
	long long ans=accumulate(v.begin(),v.end(),0ll)-csum;
	
	n-=v.size()-vc.size();
	ans+=csum*(n/vc.size());
	n%=vc.size();
	for(int i=0;i<n;i++) ans+=vc[i];
	cout<<ans;
}