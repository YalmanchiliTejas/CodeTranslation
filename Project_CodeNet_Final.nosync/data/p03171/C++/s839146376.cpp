#include<iostream>
#define ll long long
using namespace std;
ll a[3001];
ll dp[3001][3001];
ll sum[3001][3001];
int main() {
	int n;
	cin>>n;
	ll S = 0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		dp[i][i] = a[i];
		sum[i][i] = a[i];
	}
	for(int len = 2; len <= n; len++) {
		for(int i = 0; i + len - 1 < n; i++) {
			int j = i + len - 1;
			dp[i][j] = max(a[i] + sum[i+1][j] - dp[i+1][j],
						 a[j] + sum[i][j-1] - dp[i][j-1]);
			sum[i][j] = sum[i][j-1] + sum[j][j];
		}
	}
	cout<<2* dp[0][n-1] - sum[0][n-1] <<endl;
	return 0;
}
