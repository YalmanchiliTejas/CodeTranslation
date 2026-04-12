#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
using ll = long long;
using P = pair<int,int>;

// code starts
#define MOD 1000000007

ll mod_inv(ll a)
{
	ll left = MOD-2;
	ll ans = 1;
	ll ks = a;
	while(left > 0)
	{
		if(left %2 == 1)
		{
			ans = ans*ks%MOD;
		}
		ks = ks*ks%MOD;
		left /= 2;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	int i;
	rep(i,n) cin >> a[i];
	ll sums = 0;
	rep(i,n)
	{
		sums += a[i];
		sums %= MOD;
	}
	sums = sums*sums%MOD;
	rep(i,n)
	{
		ll dec = a[i]*a[i];
		dec %= MOD;
		sums = (sums-dec+MOD)%MOD;
	}
	//cout << sums << endl;
	cout << sums*mod_inv(2)%MOD << endl;
}
