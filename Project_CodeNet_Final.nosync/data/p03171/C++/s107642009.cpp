#include<bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;

int dp[3000][3000];
int find(int arr[], int i, int j) {
	if (dp[i][j] != -1)
		return dp[i][j];
	if (i == j)
		return arr[i];
	int taro = INT_MIN, jiro = INT_MAX;
	taro = max(arr[i] + find(arr, i + 1, j) - jiro, arr[j] + find(arr, i, j - 1) - jiro);
	jiro = min(taro - arr[i] + find(arr, i + 1, j), taro - arr[j] + find(arr, i, j - 1));
	return dp[i][j] = taro - jiro;
}


int32_t main() {
	int n;
	cin >> n;
	int arr[n];
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << find(arr, 0, n - 1);
	return 0;
}