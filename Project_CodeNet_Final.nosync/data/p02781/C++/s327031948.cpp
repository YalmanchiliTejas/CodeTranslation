#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>


using namespace std;
int main() {
	char c[101];
	int i = 0;
	int K;
	vector<int>N(102, 0);
	long long count = 0;
	cin >> c;
	for (i = 0; c[i] != 0; i++) {
		N[i] = c[i] - 48;
	}
	//N:i��
	cin >> K;
	int dp[101][2][4] = {0};//��,�ŏ�,0�ȊO������o����
	dp[0][0][0] = 1;
	dp[0][0][1] = N[0] - 1;
	dp[0][1][1] = 1;
	for (int j = 1; j < i; j++) {
		dp[j][0][0] = dp[j - 1][0][0] + dp[j - 1][1][0]*(!!N[j]);
		dp[j][0][1] = dp[j - 1][0][0] * 9 + dp[j - 1][0][1] + dp[j - 1][1][1] * (!!N[j]);
		dp[j][0][2]= dp[j - 1][0][1] * 9 + dp[j - 1][1][1] * (!!N[j])*(N[j]-1) + dp[j - 1][0][2]  + dp[j - 1][1][2] * (!!N[j]);
		dp[j][0][3] = dp[j - 1][0][2] * 9 + dp[j - 1][1][2] *(!!N[j]) * (N[j] - 1) + dp[j - 1][0][3] + dp[j - 1][1][3] * (!!N[j]);
		dp[j][1][1] =  dp[j - 1][1][1]*(!N[j]);
		dp[j][1][2] = dp[j - 1][1][1] * (!!N[j]) + dp[j - 1][1][2] * (!N[j]);
		dp[j][1][3] = dp[j - 1][1][2] * (!!N[j]) + dp[j - 1][1][3] * (!N[j]);
	}
	cout << dp[i - 1][1][K] + dp[i - 1][0][K] << endl;
}