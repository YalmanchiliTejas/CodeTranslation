#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define pi 2*acos(0)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
using namespace std;



int main()
{

	io;
	
	int n; cin >> n;

	
	
	vector<ll> sum,v;
	ll s = 0;
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x;
		s =(s+x)%mod;
		v.push_back(x);
		sum.push_back(s);
	}

	ll ans = 0;
	for (int i = 0; i < n-1; i++) {

		ll a = s - sum[i];
		if (a < 0)	a += mod;

		ans += v[i] * a;
		ans %= mod;

		//ans = (ans + (v[i]*(s-sum[i]))%mod ) % mod;

	}

	cout << ans;
	
}

