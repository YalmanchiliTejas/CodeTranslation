#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define inf 1000000000000
#define mod 1000000007

ll power(ll a, ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a);
        a = (a*a);
        b >>= 1;
    }
    return prod;
}

ll a[100009];
ll dp[3009][3009][2];
ll fun(ll  l , ll r , ll chance)
{
	if(l > r)
	{
		return 0;
	}
	if(dp[l][r][chance] != inf)return dp[l][r][chance];
	if(chance == 0)
	{
		dp[l][r][chance] = max(a[l] + fun(l+1 , r , chance^1) , a[r] + fun(l , r-1 , chance^1));
		return dp[l][r][chance];
	}
	else
	{
		
		return dp[l][r][chance] = min((-1)*a[l] + fun(l+1 , r , chance^1) , (-1)*a[r] + fun(l , r-1 , chance^1));
	}
	
}
signed main()
{
	ll n;
	cin >> n;
	// ll a[n];
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			for(int k = 0 ; k < 2 ; k++)
				dp[i][j][k] = inf;
	for(ll i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}

	cout << fun(0 , n-1 , 0);
 	return 0;

}


