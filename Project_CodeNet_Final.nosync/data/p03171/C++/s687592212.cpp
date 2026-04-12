#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MX 4000000000000
#define MN -4000000000000
int n;
int arr[3001];
int dp[3001][3001];
int calc(int start, int end){
	if(dp[start][end]!=MX){
		return dp[start][end];
	}
	if(end-start == 1){
		if(n&1)dp[start][end] = min(arr[start]-arr[end], arr[end]-arr[start]); 
		else   dp[start][end] = max(arr[start]-arr[end], arr[end]-arr[start]); 
		return dp[start][end];
	}
	if(((n&1) && ((end-start+1)&1)) || (!(n&1) && !((end-start+1)&1))){
		dp[start][end] = max(arr[start]+calc(start+1, end), arr[end]+calc(start, end-1));
	}
	else
		dp[start][end] = min(-arr[start]+calc(start+1, end), -arr[end]+calc(start, end-1));
	return dp[start][end];
}
signed main(){
	//freopen("input.txt","r",stdin);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = MX;
		}
	}
	calc(0, n-1);
	cout << dp[0][n-1];
	return 0;
}