#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	ll dp[n][n];// dp[be][en] is maximum X-Y the current player can get with remaining sequence from be....en
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			dp[i][j] = 0;
	}
	for(int en = 0;en < n;en++){
		for(int be = n-1;be >= 0;be--){
			if(be > en)
				continue;
			if(be == en){
				dp[be][en] = arr[be];
			}
			else{
				dp[be][en] = max(arr[be]-dp[be+1][en],arr[en]-dp[be][en-1]);
			}
		}
	}
	cout << dp[0][n-1] << "\n";
	return 0;
}