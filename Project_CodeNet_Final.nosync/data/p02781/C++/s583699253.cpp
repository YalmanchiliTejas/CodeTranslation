#include<bits/stdc++.h>
using namespace std;

#define GIRI 1
#define IKA 0

string S;
long long K;

//idx, GIRI or IKA, num
long long dp[200][2][5];

int main(){
	cin >> S >> K;

	dp[0][GIRI][0] = 1;
	for(long long i = 0; i < S.size(); i++) {
		long long num = S[i] - '0';

		//IKAからの移動
		//0
		for(long long k = 0; k <= K; k++) {
			dp[i + 1][IKA][k] += dp[i][IKA][k];
		}
		//0以外
		for(long long n = 1; n < 10; n++) {
			for(long long k = 0; k <= K; k++) {
				dp[i + 1][IKA][k+1] += dp[i][IKA][k];
			}
		}
		//GIRIからの移動
		//0
		for(long long k = 0; k <= K; k++) {
			if(num == 0) {
				dp[i + 1][GIRI][k] += dp[i][GIRI][k];
			} else {
				dp[i + 1][IKA][k] += dp[i][GIRI][k];
			}
		}
		//0< < num
		for(long long n = 1; n < num; n++) {
			for(long long k = 0; k <= K; k++) {
				dp[i + 1][IKA][k+1] += dp[i][GIRI][k];
			}
		}
		//num
		if(num != 0) {
			for(long long k = 0; k <= K; k++) {
				dp[i + 1][GIRI][k+1] += dp[i][GIRI][k];
			}
		}
	}

	cout << dp[S.size()][IKA][K] + dp[S.size()][GIRI][K] << endl;

}

