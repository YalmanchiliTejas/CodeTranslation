/******************************************
* AUTHOR : DHRUV GUPTA *
* NICK : COSMOGOD *
* INSTITUTION : LNMIIT *
******************************************/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000007

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll dp[n][n] = {0};

	for(ll l=n-1;l>=0;l--){
		for(ll r=l;r<n;r++){
			if(l==r)
				dp[l][r] = a[l];
			else
				dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
		}
	}	

	cout << dp[0][n-1];

	return 0;
}