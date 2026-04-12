#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	long long inf = 1e18; 
	long long A[200010] = {}; 
	for(int i = 1; i <= N; i++) cin >> A[i]; 
	long long dp[200010][2] = {}; // 最後に選んだのがi番目で最適個数からのロスがj個
	dp[1][0] = A[1]; dp[1][1] = -inf; 
	dp[2][0] = A[2]; dp[2][1] = -inf; 
	if(N >= 3){
		dp[3][0] = A[1] + A[3]; dp[3][1] = A[3]; 
	}
	if(N >= 4){
		dp[4][0] = max(A[1], A[2]) + A[4]; 
		dp[4][1] = A[4]; 
	}
	for(int i = 5; i <= N; i++){
		if(i % 2){
			dp[i][0] = dp[i-2][0] + A[i]; 
			dp[i][1] = max({dp[i-2][1], dp[i-3][0], dp[i-4][0]}) + A[i]; 
		}
		else{
			dp[i][0] = max(dp[i-2][0], dp[i-3][0]) + A[i]; 
			dp[i][1] = max({dp[i-2][1], dp[i-3][1], dp[i-4][0], dp[i-5][0]}) + A[i]; 
		}		
	}
	if(N % 2 == 0) cout << max(dp[N-1][0], dp[N][0]) << endl; 
	else cout << max({dp[N][1], dp[N-1][0], dp[N-2][0]}) << endl; 
}