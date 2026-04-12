#include <bits/stdc++.h>

using namespace std;

const int maxn = 3010;

long long int n;
long long int a[maxn];
long long int dp[maxn][maxn][2];

int main(){
	cin >> n;
	for (int i = 0;i < n; i++){
		cin >> a[i];
	}

	if (n == 1){
		cout << a[0] << endl;
		return 0;
	}
	
	for (int i = 0; i < n-1; i++){
		dp[i][i+1][0] = max(a[i],a[i+1]) - min(a[i], a[i+1]);
		dp[i][i+1][1] = -dp[i][i+1][0];
	}

	for (int i = 3; i <= n; i++){
		for (int j = 0; j <= n-i; j++){
			dp[j][j+i-1][0] = max(dp[j][j+i-2][1] + a[j+i-1], dp[j+1][j+i-1][1] + a[j]);
			dp[j][j+i-1][1] = min(dp[j][j+i-2][0] - a[j+i-1], dp[j+1][j+i-1][0] - a[j]);
		}
	}
	cout << dp[0][n-1][0] << endl;
	return 0;
}
