#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll power(ll x, ll y, ll p)
{ll res = 1;x = x % p;while (y > 0){if (y & 1) res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll modInverse(ll n, ll p)
{return power(n, p-2, p);}
ll nCr(ll n, ll r, ll p)
{if (r==0) return 1;ll fac[n+1];fac[0] = 1;for(ll i=1 ; i<=n; i++)fac[i] = fac[i-1]*i%p;return (fac[n]*modInverse(fac[r], p) % p * modInverse(fac[n-r], p) % p) % p;}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll i, j, k, n, m, t, p=1e9+7, temp, flag, x, y, z, count, a, b, c, d;
	cin >> n;
	ll arr[n], suf[n];
	count=0;
	ll ans=0;
	for(i=0; i<n; i++)
	{
		cin >> arr[i];
		count+=arr[i];
	}
	//cout << count << endl;
	suf[0]=count-arr[0];
	for(i=1; i<n; i++)
	{
		suf[i]=suf[i-1]-arr[i];
	}
	//cout << suf[n-1] << endl;
	for(i=0; i<n; i++)
	{
		ans += (((arr[i]%p)*(suf[i]%p))%p);
		ans%=p;
	}
	cout << ans%p << endl;
	return 0;
}
