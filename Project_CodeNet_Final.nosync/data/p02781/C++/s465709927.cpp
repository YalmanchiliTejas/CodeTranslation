#include <iostream>
#include <string>

using namespace std;

int main()
{
	string N;
	int k;
	
	cin >> N >> k;
	
	long long dp[100][2][4];
	
	dp[0][0][0] = 0;
	dp[0][0][1] = 1;
	dp[0][0][2] = 0;
	dp[0][0][3] = 0;
	dp[0][1][0] = 1;
	dp[0][1][1] = N[0]-'0'-1;
	dp[0][1][2] = 0;
	dp[0][1][3] = 0;

	for(int i = 0; i < N.length()-1; ++i) {
		int n = N[i+1]-'0';
		if(n == 0) {
			dp[i+1][0][0] = dp[i][0][0];
			dp[i+1][0][1] = dp[i][0][1];
			dp[i+1][0][2] = dp[i][0][2];
			dp[i+1][0][3] = dp[i][0][3];
			dp[i+1][1][0] = dp[i][1][0];
			dp[i+1][1][1] = dp[i][1][0]*9+dp[i][1][1];
			dp[i+1][1][2] = dp[i][1][1]*9+dp[i][1][2];
			dp[i+1][1][3] = dp[i][1][2]*9+dp[i][1][3];
		} else {
			dp[i+1][0][0] = 0;
			dp[i+1][0][1] = dp[i][0][0];
			dp[i+1][0][2] = dp[i][0][1];
			dp[i+1][0][3] = dp[i][0][2];
			dp[i+1][1][0] = dp[i][0][0]+dp[i][1][0];
			dp[i+1][1][1] = dp[i][0][0]*(n-1)+dp[i][0][1]+dp[i][1][0]*9+dp[i][1][1];
			dp[i+1][1][2] = dp[i][0][1]*(n-1)+dp[i][0][2]+dp[i][1][1]*9+dp[i][1][2];
			dp[i+1][1][3] = dp[i][0][2]*(n-1)+dp[i][0][3]+dp[i][1][2]*9+dp[i][1][3];
		}
	}
	
	cout << dp[N.length()-1][0][k]+dp[N.length()-1][1][k];
}
