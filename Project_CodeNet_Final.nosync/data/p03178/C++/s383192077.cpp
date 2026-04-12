#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define mod 1000000007LL

/*	Author: 🆉🅴🅽🅾🅻🆄🆂	*/

string k;
ll dp[10001][2][101], d;
ll count(ll i, bool tight, ll sum){
	if(i == k.size())	return (sum == 0);
	if(dp[i][tight][sum] != -1)	return dp[i][tight][sum];
	ll ans = 0, high = tight ? k[i]-'0' : 9;
	for(ll j = 0; j <= high; j++)
		ans = mop(ans, +, count(i+1, tight & (j == high), (sum+j)%d));
	return dp[i][tight][sum] = ans;
}
int main(){
	fill(dp, -1);	cin>>k>>d;
	cout<<(count(0, 1, 0) + mod - 1) % mod;
}

// Time: O(D*logK)
// Space: O(D*logK)