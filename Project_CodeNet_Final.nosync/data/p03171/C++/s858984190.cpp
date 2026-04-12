#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vll vector <pll>
#pragma 03
using namespace std;
ll n;
ll dp[3005][3005][2];
ll a[3005];
ll calc(ll l, ll r, ll c){
	if (l > r) return 0;
	if (dp[l][r][c] != -1) return dp[l][r][c];
	ll i = calc(l + 1, r, 1 - c);
	ll j = calc(l, r-1, 1 - c);
	dp[l][r][c] = c * max(a[l] + i, a[r] + j) + (1 - c) * min(i - a[l], j - a[r]);
	return dp[l][r][c];
}
int main(){
	cin >> n;
	for (ll i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<3005; i++){
		for (int j = 0; j<3005; j++){
			for (int k = 0; k<2; k++) dp[i][j][k] = -1;
		}
	}
	cout << calc(0, n-1, 1) << endl;
}	