#include <bits/stdc++.h>
#define ll long long
#define fop(i,m,n) for(ll i=m;i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
using namespace std;
int main(){
	ll n;
	cin >> n;
	ll dp[n][n];
	ll a[n];
	fop(i,0,n){
		cin >> a[i];
		dp[i][i] = a[i];
	}
	fop(i,1,n){
		for(ll l=0,r;(r = l + i) < n;l++){
			dp[l][r] = max(a[l] - dp[l+1][r] ,a[r] - dp[l][r-1]);
		}
	}
	cout << dp[0][n-1];
}