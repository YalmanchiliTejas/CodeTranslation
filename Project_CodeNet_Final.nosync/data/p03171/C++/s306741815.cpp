#include <bits/stdc++.h>
using namespace std;

int a[3001];
long long dp[3001][3001][2];

int main(){

	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = n - 1; i >= 0; i--){
		for(int j = i; j < n; j++){
			for(int p = 0; p < 2; p++){
				if(i == j){
					dp[i][j][p] = a[i];
					continue;
				}
			
				dp[i][j][p] = max(-dp[i + 1][j][!p] + a[i], -dp[i][j - 1][!p] + a[j]);
			}
		}
	}
	cout << dp[0][n-1][0];

}



