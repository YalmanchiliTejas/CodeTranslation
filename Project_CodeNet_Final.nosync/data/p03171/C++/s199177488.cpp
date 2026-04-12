#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
const ll  M = 1e9 + 7;
ll n, k, x = 0, y = 0;

ll dp[3002][3002][2];

ll f(ll l, ll r, vector<ll> &v, ll turn)
{

	if(l > r)
	{
		
		return 0;
		
	}
	if(dp[l][r][turn] != -1)
		return dp[l][r][turn];
	// turn is to tell whos turn it is now (which player) : 0 -> X
	// option1 I take from l, option2 i take from right end

	if(turn == 0)
	{
		ll opt1 = f(l + 1, r, v, !turn) +v[l];
		ll opt2 = f(l, r-1, v, !turn) +v[r];
		return dp[l][r][turn] = max(opt1, opt2);
	}
	else
	{
		ll opt1 = f(l + 1, r, v, !turn) -v[l];
		ll opt2 = f(l, r-1, v, !turn) -v[r];
		return dp[l][r][turn] = min(opt1, opt2);
	}

	
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll i, j, wt, m;
	
	cin >> n;
	vector<ll> v(n + 1);
	for(i = 0; i < n; i++)
		cin >> v[i];
	memset(dp, -1, sizeof(dp));
	cout << f(0, n-1, v, 0);
}
