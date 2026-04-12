#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll n;
ll a[3005], dp[3005][3005];

ll fn(ll i, ll j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i == j)
		return a[i];
	if(i+1 == j)
		return max(a[i], a[j]);
	ll x1 = a[i] + min(fn(i+2, j), fn(i+1, j-1));
	ll x2 = a[j] + min(fn(i+1, j-1), fn(i, j-2));
	dp[i][j] = max(x1, x2);
	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ll s = 0;
	for(ll i=0; i<n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	memset(dp, -1, sizeof dp);
	ll y =  s - fn(0, n-1);
	cout << fn(0, n-1) - y << "\n";

	return 0;
}