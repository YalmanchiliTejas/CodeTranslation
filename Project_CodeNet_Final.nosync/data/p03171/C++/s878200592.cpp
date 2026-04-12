#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
	ll n;
	cin >> n;
	vector <ll> value(n);
	vector <ll> sum(n + 1,0);
	for(ll i = 0;i < n;i++){
		cin >> value[i];
		sum[i + 1] = sum[i] + value[i];
	}
	vector <vector <ll>> dp(n+1,vector <ll>(n + 1,0));
	for(ll i = 0;i < n;i++){
		dp[i][i]= value[i];
	}
	for(ll i = 2;i <= n;i++){
		for(ll j = 0;j < n;j++){
			if(j + i > n) break;
				dp[j][j + i - 1] = max(sum[j + i] - sum[j] - dp[j+1][j+i-1],sum[j + i] - sum[j] - dp[j][j + i - 2]);
		}
	}
	ll x = dp[0][n - 1];
	if(x == sum[n] - sum[0] - dp[1][n - 1]){
		cout << x - dp[1][n - 1];
	}
	else{
		cout << x - dp[0][n - 2];
	}
 	return 0;
}