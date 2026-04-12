#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <map>
const int MOD = 1e9+7;
using namespace std;

int ctoi(char c){
	return c - '0';
}

long long dp[101][2][4];

int main(){
	string s;
	int k;
	cin >> s >> k;

	for (int i = 1; i <= s.length(); i++){
		dp[i][0][0] = 1;
	}
	dp[1][0][1] = max(ctoi(s[0])-1, 0);
	dp[1][1][1] = 1;
	for (int i = 2; i <= s.length(); i++){
		for (int j = 1; j <= k; j++){
			dp[i][0][j] = dp[i-1][0][j-1]*9 + dp[i-1][1][j-1]*max(ctoi(s[i-1])-1, 0) + dp[i-1][0][j];
			if (ctoi(s[i-1]) != 0){
				dp[i][0][j] += dp[i-1][1][j];
				dp[i][1][j] = dp[i-1][1][j-1];
			}else{
				dp[i][1][j] = dp[i-1][1][j];
			} 
		}
	}

	cout << dp[s.length()][0][k] + dp[s.length()][1][k] << endl;
	return 0;
}
