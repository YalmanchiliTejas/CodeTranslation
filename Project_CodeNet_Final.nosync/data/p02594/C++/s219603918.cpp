/******************************************
* AHAM BRAHMASHMI ;) *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod 1000000007


template <class T>
void print(vector<T> arr)
{
	cout << "start printing the vector\n";
	for (auto u : arr)
		cout << u << " ";
	cout << "\n";
}

template <class T>
void print_mat(vector<vector<T>> a)
{
	cout << "start printing the matrix\n";
	for (auto v : a)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << "\n";
	}
}

/******************************************
* NUMBER THEORY ;) *
******************************************/



ll powermod(ll x, ll y)
{
	ll res = 1;
	x = x % mod;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x * x) % mod;
	}
	res %= mod;
	return res;
}
ll factmod(ll n)
{
	ll res = 1;
	while (n > 1)
	{
		res = (res * ((n / mod) % 2 ?  mod - 1 : 1)) % mod;
		for (ll i = 2; i <= n % mod; ++i)
			res = (res * i) % mod;
		n /= mod;
	}
	res %= mod;
	return res;
}



void solve()
{
	ll n;
	cin >> n;
	if (n >= 30)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// ll t;
	// cin>>t;
	// while(t--)
	// {
	solve();
	// }

	return 0;
}