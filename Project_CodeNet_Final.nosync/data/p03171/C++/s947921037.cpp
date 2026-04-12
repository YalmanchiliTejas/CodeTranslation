#include "bits/stdc++.h"
using namespace std;

// 2*X - C  ->  X
long long dp[3000][3000][2]; // resulting value of X

// dp[L][R][p] = (L....R) inclusive, pth player turn
// p = 0 -> first, p = 1 -> second

// base cases
// dp[i][i][0] = a[i]
// dp[i][i][1] = 0

// Transitions
// pick L or pick R
// dp[L][R][0] = max(a[L] + dp[L+1][R][1],
// 					a[R] + dp[L][R-1][1])
// dp[L][R][1] = min(dp[L+1][R][0],
// 					dp[L][R-1][0])

// Order of Evaluation
// increasing of (R-L)

// ans = 2*(dp[0][n-1][0]) - sum

int main(){
	long long n, sum = 0;
	cin>>n;
	vector<long long> a(n);
	for(long long& x:a){
		cin>>x;
		sum += x;
	}
	
	for(long long i = 0; i < n; i++){
		dp[i][i][0] = a[i];
		dp[i][i][1] = 0;
	}
	
	for(long long RminusL = 1; RminusL < n; RminusL++){
		for(long long L = 0; L + RminusL < n; L++){
			long long R = L + RminusL;
			dp[L][R][0] = max(a[L] + dp[L+1][R][1],
							a[R] + dp[L][R-1][1]);
			
			dp[L][R][1] = min(dp[L+1][R][0],
							dp[L][R-1][0]);
		}
	}
	
	long long X = dp[0][n-1][0]; // (0...n-1) first player move
	long long ans = 2*X - sum;
	cout<<ans;
}
