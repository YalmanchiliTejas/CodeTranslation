#include<cstdio>
#include <iostream>
#include<algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1000000007;
ull dp[105][4][2];

int main(){
	string S;
	cin >> S;
	int K;
	scanf("%d", &K);
	for (int i = 0; i <= K; ++i)
	{
		dp[0][i][0] = dp[0][i][1] = 0;
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= S.length(); ++i){
		for (int j = 0; j <= K; ++j){
			if(S[i - 1] == '0'){
				dp[i][j][0] = dp[i - 1][j][0];
				dp[i][j][1] = dp[i - 1][j][1];
				if(j > 0){
					dp[i][j][1] += 9*dp[i - 1][j - 1][1];
				}
			}else if(j > 0){
				dp[i][j][0] = dp[i - 1][j - 1][0];
				dp[i][j][1] = 9*dp[i - 1][j - 1][1] + dp[i - 1][j][0] + dp[i - 1][j][1] + (S[i - 1] - '1')*dp[i - 1][j - 1][0];
			}else{
				dp[i][j][0] = 0;
				dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j][1];
			}
		}
	}
	printf("%llu\n", dp[S.length()][K][0] + dp[S.length()][K][1]);
	return 0;
}