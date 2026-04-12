#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define here(x) cout << " #x = " << x << endl;
#define show(x) {for( auto ii : x) cout << ii << setw(4); cout << endl;}
#define shop(n,x) {for(int i = 0; i < n; i++) cout << x << setw(4); cout << endl;}
#define ff first
#define ss second
#define sq(x) (x*x)
#define endl '\n'
#define en " "
#define pb push_back
#define mpair make_pair
ll mod=1000000007;
double pi=3.1415926536;
ll dp[4000][4000];
ll win(ll a[], ll l, ll h)
{
	if(dp[l][h] != -1)
		return dp[l][h];

	if(l == h)
		return a[l];

	ll n = h - l + 1;

	if(n % 2)
		return dp[l][h] = max(a[l] + win(a, l + 1, h), a[h] + win(a, l, h - 1));

	return dp[l][h] = min(- a[l] + win(a, l + 1, h), - a[h] + win(a, l, h - 1));
}
int main()
{
	fastio();
	int tt = 1;
	//cin >> tt;
	while(tt--)
	{
		// go fast 		check		//		CHECK -> if()   else if()
		
		ll n, x=0, m=0, y=0, d=1, k=mod;
		cin >> n;
		ll a[n];
		for(ll i = 0; i < n; i++)
			cin >> a[i];
		memset( dp, -1, sizeof(dp));
		x = win(a, 0, n - 1);
		if(n % 2)
			cout << x << endl;
		else
			cout << - x << endl;
	}
}