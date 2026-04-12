#include <bits/stdc++.h>
using namespace std;
int n;
int arr[5000];
long long dp[3005][3005];
long long rec(int l, int r){
	if(l == r)return arr[l];
	if(dp[l][r] != -1)return dp[l][r];
	return dp[l][r] = max(arr[l] - rec(l+1, r), arr[r] - rec(l, r-1));
}
int main(){
	cin >> n;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			dp[i][j] = -1;
	for(int i = 0; i < n ; i++)cin >> arr[i];
	cout << rec(0, n-1);
}