#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define F first
#define S second
#define pb push_back
#define mp make_pair

ll gcd(ll a, ll b){
	if (a == 0) return b;
	return gcd(b%a, a);
}

ll lcm(ll a, ll b){
	return (a/gcd(a, b))*b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n,i,j,sum= 0,sum1 = 0;

	cin >> n;
	ll a[n];

	for(i=0;i<n;i++)
	{
		cin >> a[i];
		sum1 += a[i];
	}

	sum1 -= a[0];
	ll f = 1e9 + 7;
	for(i=0;i<n-1;i++)
	{
		ll x = sum1;
		x %= f;

		ll w = a[i]%f;

		x*=w;
		sum += x%f;

		sum1 -= a[i+1];
	}

	cout << sum%f << endl;
}