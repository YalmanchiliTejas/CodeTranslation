#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>A(n, 0);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	vector< vector<long long int> > dp(n, vector<long long int> (n, 0) );
	for(int i = 0; i < n; i++){
		dp[i][i] = A[i];
	}
	for(int k = 1; k < n; k++){
		for(int i = 0; (i + k) < n; i++){
			dp[i][i+k] = max(A[i] - dp[i+1][i+k], A[i+k] - dp[i][i+k-1]);
		}
	}
	cout << dp[0][n-1] << endl;
}
