#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <vector>
#define loop(n) for(ll i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
#define Mxn 3001

ll n;
ll arr[Mxn];


bool taro(ll rem)
{
	if(n%2 == 0 && rem%2 == 0)
		return true;
		
	if(n%2 != 0 && rem%2 != 0)
		return true;
		
	return false;
}

ll solve(ll start,ll end)
{

	ll rem = end - start + 1;
	
	if(start == end)
	{
		if(taro(rem))
			return arr[start];
		else
			return -arr[start];
	}
		
	
	if(taro(rem))
	{
		return max(arr[start] + solve(start+1,end),arr[end] + solve(start,end-1));
	}
	else
	{
		return min(solve(start+1,end) - arr[start],solve(start,end-1) - arr[end]);
	}
	
	
}

ll dpsolve()
{
	ll dp[n][n];
	
	for(ll k=1;k<=n;k++)
	{
		for(ll i=0;i<=n-k;i++)
		{
			ll j = i + k - 1;
			ll rem = j - i + 1;
			if(i == j)
			{
				if(taro(rem))
					dp[i][j] = arr[i];
				else
					dp[i][j] = -arr[i];
			}
			else
			{
				if(taro(rem))
					dp[i][j] = max(arr[i] + dp[i+1][j],arr[j] + dp[i][j-1]);
				else
					dp[i][j] = min(dp[i+1][j] - arr[i],dp[i][j-1] - arr[j]);
			}
		}
	}
	return dp[0][n-1];
}
					




int main()
{
    fastio;
    cin>>n;
    loop(n)
		cin>>arr[i];
	
	ll ans = dpsolve();
	cout<<ans<<endl;
    return 0;
}
