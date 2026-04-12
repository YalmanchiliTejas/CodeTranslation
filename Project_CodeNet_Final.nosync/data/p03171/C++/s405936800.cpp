#include <bits/stdc++.h>
using namespace std;
long long dp[3001][3001];
long long util(int arr[], int left, int right){
    if(left > right) return 0;
    if(dp[left][right] != -1) return dp[left][right];
    return dp[left][right] = max(arr[left] + min(util(arr, left + 1, right - 1), util(arr, left + 2, right)), arr[right] + min(util(arr, left + 1, right - 1), util(arr, left, right - 2)));
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	long long sum = 0;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    sum += arr[i];
	}
	memset(dp, -1, sizeof(dp));
	long long x = util(arr, 0, n-1);
	cout<<(2*x - sum);
	return 0;
}