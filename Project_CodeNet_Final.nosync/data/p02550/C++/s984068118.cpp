#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n,x,m;
	cin>>n>>x>>m;
	set<ll> s;
	ll p[m] = {};
	ll cnt = 0;
	ll sum = 0;
	vector<ll> v;
	while(s.find(x%m)==s.end())
	{
		s.insert(x%m);
		sum += x%m;
		v.push_back(x%m);
		cnt++;
		x = (x*x)%m;
	}
	if(v[v.size()-1]==0)
	{
		cout<<sum<<endl;
		return;
	}
	// cout<<v.size()<<endl;
	ll ans = 0;
	int i;
	for (i = 0; i < v.size(); ++i)
	{
		if(v[i]==x)
			break;
		cnt--;
		n--;
		ans += v[i];
		sum -= v[i];
	}

	// cout<<n<<endl;
	ans += (n/cnt)*sum;
	n %= cnt;

	for (int j = 0; j < n; ++j)
	{
		ans += v[i+j];
	}
	cout<<ans<<endl;
}

int main()
{
	ll t = 1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}