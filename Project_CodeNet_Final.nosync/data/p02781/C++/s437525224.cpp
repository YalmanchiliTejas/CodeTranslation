#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;
using P = pair<int, int>;

long long int dp[2][110][4];
//0->未確定,1->確定
int main()
{
	string N;
	int K;
	cin >> N;
	cin >> K;
	
	int D = N.size();
	dp[0][0][0] = 1;
	for (int i = 1; i <= D; i++) {
		int d = N[i-1] - '0';
		if (d != 0) {
			dp[0][i][1] = dp[0][i - 1][0];
			dp[0][i][2] = dp[0][i - 1][1];
			dp[0][i][3] = dp[0][i - 1][2];
			dp[1][i][0] = dp[1][i - 1][0] + dp[0][i - 1][0];
			dp[1][i][1] = 9 * dp[1][i - 1][0] + (d - 1) * dp[0][i - 1][0] + dp[1][i - 1][1] + dp[0][i - 1][1];
			dp[1][i][2] = 9 * dp[1][i - 1][1] + (d - 1) * dp[0][i - 1][1] + dp[1][i - 1][2] + dp[0][i - 1][2];
			dp[1][i][3] = 9 * dp[1][i - 1][2] + (d - 1) * dp[0][i - 1][2] + dp[1][i - 1][3] + dp[0][i - 1][3];
		}
		else {
			dp[0][i][0] = dp[0][i - 1][0];
			dp[0][i][1] = dp[0][i - 1][1];
			dp[0][i][2] = dp[0][i - 1][2];
			dp[0][i][3] = dp[0][i - 1][3];
			dp[1][i][0] = dp[1][i - 1][0];
			dp[1][i][1] = 9 * dp[1][i - 1][0] + dp[1][i - 1][1];
			dp[1][i][2] = 9 * dp[1][i - 1][1] + dp[1][i - 1][2];
			dp[1][i][3] = 9 * dp[1][i - 1][2] + dp[1][i - 1][3];
		}
	}
	cout << dp[0][D][K] + dp[1][D][K] << endl;
}