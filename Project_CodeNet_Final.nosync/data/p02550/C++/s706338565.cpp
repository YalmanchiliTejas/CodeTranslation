#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n,x,mp;
	cin>>n>>x>>mp;
	map<long long int,long long int> m;
	vector<long long int> a;
	long long int ind=0,sum=x;
	a.push_back(x);
	m[x]=ind;
	ind++;
	x=(x*x)%mp;
	while(ind<n && m.find(x)==m.end())
	{
		sum+=x;
		a.push_back(x);
		m[x]=ind;
		ind++;
		x=(x*x)%mp;
	}
	if(ind==n)
	{
		cout<<sum<<'\n';
	}
	else
	{
		long long int rem=n-a.size();
		long long int newind=m[x];
		long long int sz=a.size()-newind;
		long long int extra=rem%sz;
		long long int newsum=0;
		for(long long int i=0;i<extra;i++)
		{
			newsum+=a[i+newind];
		}
		sum+=newsum;
		for(long long int i=extra;i+newind<a.size();i++)
		{
			newsum+=a[i+newind];
		}
		sum+=newsum*(rem/sz);
		cout<<sum<<'\n';
	}
}
