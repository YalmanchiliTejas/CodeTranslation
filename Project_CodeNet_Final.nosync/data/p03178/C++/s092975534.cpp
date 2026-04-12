#include <bits/stdc++.h>
using namespace std;
int d,dp[100005][101][2];
string k;

int main(){
	cin >> k >> d;
	dp[0][0][1] = 1;
	for(int i = 1 ; i <= k.size() ; i += 1){
		for(int j = 0 ; j < d ; j += 1){
			for(int ii = 0 ; ii < k[i-1]-'0' ; ii += 1){
				dp[i][(j+ii)%d][0] += dp[i-1][j][1];
				if(dp[i][(j+ii)%d][0] >= 1000000007){
					dp[i][(j+ii)%d][0] -= 1000000007;
				}
			}
			dp[i][(j+(k[i-1]-'0'))%d][1] += dp[i-1][j][1];
			if(dp[i][(j+(k[i-1]-'0'))%d][1] >= 1000000007){
				dp[i][(j+(k[i-1]-'0'))%d][1] -= 1000000007;
			}
			for(int ii = 0 ; ii < 10 ; ii += 1){
				dp[i][(j+ii)%d][0] += dp[i-1][j][0];
				if(dp[i][(j+ii)%d][0] >= 1000000007){
					dp[i][(j+ii)%d][0] -= 1000000007;
				}
			}
		}
	}
	cout << (long long)(dp[k.size()][0][0]+dp[k.size()][0][1]+1000000006)%1000000007 << endl;
}