#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll mod = 1e9 + 7;

void solve()
{
	ll n;
	cin >> n;
	ll x, m;
	cin >> x >> m;
	vector <ll> s;
	ll ele = 1;
	map <ll,int> mp1;
	while(1)
	{
		if(mp1.find(x) != mp1.end())
		{
			ele = x;
			break;
		}
		mp1[x] = 1;
		s.push_back(x);
		x = (x%m)*(x%m);
		x %= m;
	}
	ll sum = 0;
	vector <ll> v;
	int ok = 0;
	for(auto i : s)
	{
		if(!n) break;
		if(i == ele) ok = 1;
		if(ok)
		{
			v.push_back(i);
		}
		else
		{
			sum += i;
			n--;
		}
	}
	for(int i = 1; i < v.size(); i++)
	{
		v[i] += v[i - 1];
	}
	if(v.size())
	{
		ll p = n / ((int)v.size());
		sum += (p*v[(int)v.size()-1]);
		ll c = n % ((int)v.size());
		if(c > 0) sum += v[c - 1];
	}
	cout << sum << "\n";
	
}

int main()
{
//	cin.sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--)
	{
		solve();
	}
}
