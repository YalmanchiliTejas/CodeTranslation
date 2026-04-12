#include <iostream>
using namespace std;
long long a[100005];
long long dp[3005][3005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
			dp[j][j+i-1]=max(a[j]-dp[j+1][j+i-1],a[j+i-1]-dp[j][j+i-2]);
	}
	cout << dp[1][n];
	return 0;
}