#include <bits/stdc++.h>
using namespace std;

#define MAXN 3001

int A[MAXN],N;
long long dp[MAXN][MAXN][2];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		dp[i][i][0] = A[i];
	}
	for(int k = 1; k < N; k++){
		for(int i = 0,j = k; j < N; i++,j++){
			// better choice is the take the leftmost item 
			if(A[i] + dp[i + 1][j][1] > A[j] + dp[i][j - 1][1]){
				dp[i][j][0] = A[i] + dp[i + 1][j][1];
				dp[i][j][1] = dp[i + 1][j][0];
			}else{
				dp[i][j][0] = A[j] + dp[i][j - 1][1];
				dp[i][j][1] = dp[i][j - 1][0];
			}
		}
	}
	cout << dp[0][N - 1][0] - dp[0][N - 1][1];
	return 0;
}