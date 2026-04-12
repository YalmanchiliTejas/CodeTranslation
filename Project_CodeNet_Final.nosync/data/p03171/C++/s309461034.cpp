#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<long long>>dp(n,vector<long long>(n,0));

	vector<int>arr(n);
	for(int& i:arr) cin >> i;

	for(int l=n-1;l>=0;l--){
		for(int r=l;r<n;r++){
			if(l == r){
				dp[l][r] = arr[l];
			}else{
				dp[l][r] = max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
			}
		}
	}

	cout << dp[0][n-1] << endl;

	return 0;
}
