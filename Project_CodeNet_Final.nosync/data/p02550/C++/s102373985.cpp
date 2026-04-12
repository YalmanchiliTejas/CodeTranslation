#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Scenario #"<<x<<": "
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;





void solve(int t)
{

	ll n, x, m;

	cin >> n >> x >> m;
	map<ll, ll> mp;

	ll d = x;
	vector<ll> v;
	while (true)
	{
		d %= m;
		if (mp[d] > 0) break;
		v.pb(d);
		mp[d]++;
		d = (d * d);
	}

	//cout << d << endl;

	ll idx = 0;

	ll k = 0;
	for (auto i : v)
	{
		if (i == d) { idx = k; break; }
		k++;
	}

	//cout << idx << " " << v[idx] << " " << d << endl;

	ll sum = 0;

	for (int i = 0; i < min(n, (ll)v.size()); i++) sum += v[i];
	ll sz = v.size();




	if (n > sz)
	{
		n -= sz;
		vector<ll> vv;
		ll ss = 0;
		for (int i = idx; i < v.size(); i++)
		{
			ss += v[i];
			vv.pb(ss);
		}

		ll z = vv.size();
		sum += (n / z) * ss;
		if (n % z != 0)
			sum += vv[n % z - 1];
	}

	cout << sum << endl;


}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);





	int t = 1;
	//cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}