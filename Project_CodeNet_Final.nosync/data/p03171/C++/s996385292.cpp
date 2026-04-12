#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin >>n;
	vector<ll> v(n+1);
	for(int i = 1; i <= n;++i) cin>>v[i];
	vector<vector<ll>> dp(n+2,vector<ll> (n+2));
	for(int L = n;L>0;L--) 
		 for(int R = L;R <= n;R++) 
		 	 dp[L][R] = max(v[L]-dp[L+1][R],v[R]-dp[L][R-1]);

	cout <<dp[1][n]<<'\n';
	return 0;
}