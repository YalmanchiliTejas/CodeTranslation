#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, S; cin >> N >> S; 
	long long A[3010] = {}; 
	for(int i = 0; i < N; i++) cin >> A[i]; 
	long long P = 998244353;  
	long long dp[3010][3010] = {}; 
	dp[0][0] = 1LL; 
	for(long long i = 0; i < N; i++){
		for(long long j = 0; j < S; j++){
			dp[i+1][j] += dp[i][j]; dp[i+1][j] %= P; 
			if(j == 0 && A[i] == S){
				dp[i+1][S] += (i + 1) * (N - i); dp[i+1][S] %= P; 
			}
			else if(j == 0){
				dp[i+1][A[i]] += i + 1; dp[i+1][A[i]] %= P; 
			} 
			else if(j + A[i] == S){
				dp[i+1][S] += dp[i][j] * (N - i) % P; 
				dp[i+1][S] %= P; 
			}
			else if(j + A[i] > S) continue; 
			else{
				dp[i+1][j + A[i]] += dp[i][j]; 
			}
		}
		dp[i+1][S] += dp[i][S]; dp[i+1][S] %= P; 
	}
	cout << dp[N][S] << endl; 
}