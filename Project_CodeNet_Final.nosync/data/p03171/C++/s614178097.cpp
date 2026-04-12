#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
#define int ll
int32_t main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a)
		cin>>i;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for(int i = n ; i > 0 ; i--){
		for(int j = i ; j <= n ;j++){
			if(i == j){
				dp[i][j] = a[i - 1];
			}else{
				dp[i][j] = max(a[i - 1] - dp[i + 1][j], a[j - 1] - dp[i][j - 1]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
}