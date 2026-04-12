#include<bits/stdc++.h>
#define SPEED ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long int
#define inf 999999999
#define maxn 100003
const ll mod = 1e9+7;
using namespace std;
void code()
{
	ll n, sum = 0;
	cin >> n;
	ll ar[n];
	for (ll i = 0; i < n; ++i)
	{
		cin >> ar[i];
	}
	ll suffixarray[n];
	suffixarray[n-1] = ar[n-1];
	for(ll  i = n-2; i>= 0; --i)
	{
		suffixarray[i] = suffixarray[i+1]+ar[i];
		suffixarray[i] = suffixarray[i]%mod;
	}
	ll ans = 0;
	for(ll i = 0; i < n-1; i++)
	{
		sum = (suffixarray[i+1]*ar[i])%mod;
		ans+=sum;
		ans%=mod;
	}
	cout << ans;
}
int main()
{
	SPEED
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.out","w",stdout);
	#endif
	int t = 1;
	while(t--)
	{
		code();
	}
}