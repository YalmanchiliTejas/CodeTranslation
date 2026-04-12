#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector <ll>
ll n;
vec arr;
ll dp[3001][3001][2];
ll func(ll l,ll r,bool turn) {
	if(l > r)
		return 0;
	if(dp[l][r][turn] != -1)
		return dp[l][r][turn];
	ll v1 = func(l + 1,r,!turn);
	ll v2 = func(l,r -1,!turn);
	if(turn) {
		dp[l][r][turn] = max(v1 + arr[l],v2 + arr[r]);
	}
	else
		dp[l][r][turn] = min(v1,v2);
	return dp[l][r][turn];
}	
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	arr.resize(n);
	ll i,j,k;
	for(i = 0 ; i <= n ; i++)
		for(j = 0 ; j <= n ; j++)
			for(k = 0; k < 2 ; k++)
				dp[i][j][k] = -1;
	for(i = 0 ; i < n ; i++)
		cin >> arr[i];
	ll x = func(0,n-1,true);
	ll y = func(0,n-1,false);
	cout << x - y;
	return 0;
}