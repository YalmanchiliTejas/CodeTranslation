#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<vector<long long> > dp(n,vector<long long>(n));
	for(int i = 0; i < n; i++){
		cin >> a[i];
		dp[i][i] = a[i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n-i; j++){
			int l = j, r = j + i;
			dp[l][r] = max(-dp[l+1][r] + a[l] , -dp[l][r-1] + a[r]);  
		}
	}
	cout << dp[0][n-1] << "\n";
	return 0;
}
