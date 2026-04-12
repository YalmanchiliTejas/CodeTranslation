#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

string N;
int K;
ll dp[100 + 10][2][4];

int main() {
	cin >> N >> K;
	dp[0][1][0] = 1;
	for (int i = 0; i < N.size(); i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k <= K; k++) {
				for (int d = 0; d <= (j ? N[i] - '0' : 9); d++) {
					if(d == 0)
						dp[i + 1][(!j) ? 0 : ((d == (N[i] - '0')) ? 1 : 0)][k] += dp[i][j][k];
					else if(k != K)
						dp[i + 1][(!j) ? 0 : ((d == (N[i] - '0')) ? 1 : 0)][k + 1] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
	return 0;
}