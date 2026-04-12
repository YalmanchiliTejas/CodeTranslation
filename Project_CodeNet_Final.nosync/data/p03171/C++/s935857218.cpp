#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int N; 
	cin >> N; 
	long long int A[3010] = {}; 
	long long int sum = 0; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; 
		sum += A[i]; 
	}
	long long int dp[3010][3010] = {}; //dp[上からi枚とった][下からj枚とった] = 残りの太郎のmax
	for(int s = N - 1; s >= 0; s--){
		for(int i = 0; i <= s; i++){
			int j = s - i; 
			if(s % 2 == 1){ // 次は二郎君
				dp[i][j] = min(dp[i+1][j], dp[i][j+1]); 
			}
			if(s % 2 == 0){ // 次は太郎君．上からi+1枚目or下からj+1枚目
				dp[i][j] = max(A[i] + dp[i+1][j], A[N-j-1] + dp[i][j+1]); 
			}
		}
	}
	cout << dp[0][0] * 2 - sum << endl; 
}