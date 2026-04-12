#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	
	vector<vector<ll>> dp(n,vector<ll>(n));
	
	for(int i = n-1; i >= 0; i--){
		for(int j = i; j < n; j++){
			if(i==j){
				dp[i][j] = a[i];
			}
			else{
				dp[i][j] = max( a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
			}
		}
	}
	
	cout << dp[0][n-1] << endl;
	return 0;
}